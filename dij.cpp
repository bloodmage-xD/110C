//author - Andrew
// professor : Max
// this program implements dijkstra's shortest path algorithm

#include <iostream>
#include <vector>
#include <limits>
#define vertice 6


template<typename T>
class Matrix{
    std::vector<std::vector<T>> matrix;
    public:
        Matrix() = default;
        Matrix(int row, int col) : matrix(row){
            for (int i = 1; i <= row; i++)
                matrix[i].resize(col);
        }
        std::vector<T> & operator[] (int col){
            return matrix[col];   
        }
        int numrow() const{
            return matrix.size();   
        }
};
int distance(int newpath[], bool visited[]){
	int min = INT_MAX,  count = 0;
	for (int i = 0; i < vertice; i++){
		if (visited[i] == false && min >= newpath[i])
			min = newpath[i], count = i;
	}
	return count;
}

void print(int newpath[]){
	for (int i = 0; i < vertice; i++)
		std::cout << i << "   " << newpath[i] << std::endl;
}
void dijstra(int graph[vertice][vertice], int src ){
    int newpath[vertice];
    bool visited[vertice];    
    for (int i = 0; i < vertice; i++)
        newpath[i] = INT_MAX, visited[i] = false;
    newpath[src] = 0;
   
    for (int row = 0; row < vertice-1; row++){
	int count = distance(newpath, visited);
    	visited[count] = true;
    for (int col = 0; col < vertice; col++)
	if(!visited[col] &&  newpath[count] + graph[count][col] < newpath[col])
		newpath[col] = newpath[count] + graph[count][col];
   }
   print(newpath);
}
int main(){
	int graph[vertice][vertice] = {{0, 120, 150, 999, 999, 500},
					{120, 0 , 999, 75, 999, 350},
					{150, 999, 0, 999, 250, 999},
					{999, 75, 999, 0, 150, 999},
					{999, 999, 250, 150, 0, 999},
					{500, 350, 999, 999, 999, 0},
					};

	dijstra(graph, 0);    
    
}
/*
0   0
1   120
2   150
3   195
4   345
5   470



*/
