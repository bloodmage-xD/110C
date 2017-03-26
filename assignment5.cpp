// professor max
// this program calculats the amount of comparsion of sorts


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void bubble(int array[], int size){
	int counter = 0;
	for (int i = 0; i <= size; i++){
		for (int j = 0; j < size - i - 1; j++){
			counter++;
			if (array[j] > array[j + 1] )
				
				std::swap(array[j] , array[j+1]);
		}
	}
	std::cout << std::endl << std::endl << "counter is for bubblesort " << counter << std::endl << std::endl;
}
void bucket (int arr[], int n)
{
  int count = 101;
  int counter = 0;
  int a[count];
 
  for (int i = 0; i < count; ++i)
    a[i] = 0;
 
  for (int i = 0; i < n; ++i)
    ++a[arr[i]];
 
  for (int i = 0, j = 0; j < count; j++)
    for (int k = a[j]; k > 0; k--){
      counter++;
      arr[i++] = j;
  }

}
template<typename T>
void merge(T array[],T size, T low, T middle, T  high){   // takes turns swapping elements from partitions into new array
    int counter = 0;
    T temp[size];
    for (std::size_t i = low; i <= high; i++)
        temp[i] = array[i];
    T i = low;
    T j = middle + 1;
    T k = low;
        while (i <= middle && j <= high){
        if (temp[i] <= temp[j]){
            array[k] = temp[i];
            ++i;
        }
        else{
            array[k] = temp[j];
            j++;
	    counter++;
        }
        k++;
        }
        while (i <= middle){
            counter++;
	    array[k] = temp[i];
            k++; i++;

        }
}
template<typename T>
void mergesort(T array[],T size, T  low , T high){
	int counter= 0;
	if (high > low){                   // does most of the recursive calls
	counter++;
        int middle = (low + high) / 2;
        mergesort( array, size, low, middle);
        mergesort( array, size , middle+1, high);
        merge(array, size, low, middle, high);
    }
}
int random(int array4[]){
	srand(time(NULL));
	for ( int i = 0; i <= 99; i++)
		array4[i] = rand() % 99 + 1; 
	return 0;
}
void print(int array[], int size){
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " " << std::endl;;
}

int main(){
	srand(time(NULL));
	int array[8];
	int array2[32];
	int array3[] = {1,354,4354,323,234,234};
	int array4[128];
	random(array);
	random(array4);	
	random(array2);

	 std::cout << "8 pass counters" << std::endl;
        int size = sizeof(array) / sizeof(array[0]);
        std::cout << std::endl;
        bubble(array, size); random(array); print(array, size);
	 bubble(array, size); random(array); print(array, size);
	 bubble(array, size); random(array); print(array, size);
	bucket(array, size); random(array);// print (array, size);
	   bucket(array, size); random(array);// print(array, size);
	   bucket(array, size); random(array); //print(array, size);
	mergesort(array, size, 0 , 7);// print (array, size);
	mergesort(array, size, 0 , 7);// print (array, size);
	mergesort(array, size, 0 , 7);// print (array, size);

	  std::cout << "32 pass counters" << std::endl;
        size = sizeof(array2) / sizeof(array2[0]);
        std::cout << std::endl;
        bubble(array2, size); random(array2); //print(array2, size);
         bubble(array2, size); random(array2);// print(array2, size);
         bubble(array2, size); random(array2);// print(array2, size);
        bucket(array2, size); random(array2);// print (array2, size);
           bucket(array2, size); random(array2);// print(array2, size);
           bucket(array2, size); random(array2);// print(array2, size);
        mergesort(array2, size, 0 , 31);// print (array2, size);
        mergesort(array2, size, 0 , 31);// print (array2, size);
        mergesort(array2, size, 0 , 31);// print (array2, size);

        std::cout << "128 pass counters" << std::endl;
         size = sizeof(array4) / sizeof(array4[0]);
        std::cout << std::endl;
        bubble(array4, size); random(array4); //print(array4, size);
         bubble(array4, size); random(array4);// print(array4, size);
         bubble(array4, size); random(array4);// print(array4, size);
        bucket(array4, size); random(array4);// print (array4, size);
           bucket(array4, size); random(array4);// print(array4, size);
           bucket(array4, size); random(array4);// print(array4, size);
        mergesort(array4, size, 0 , 127);// print (array, size);
        mergesort(array4, size, 0 , 127);// print (array, size);
        mergesort(array4, size, 0 , 127);// print (array, size);
}

/*
8 pass counters



counter is for bubblesort 28

31 
38 
34 
87 
54 
54 
7 
82 


counter is for bubblesort 28

31 
38 
34 
87 
54 
54 
7 
82 


counter is for bubblesort 28

31 
38 
34 
87 
54 
54 
7 
82 
32 pass counters



counter is for bubblesort 496



counter is for bubblesort 496



counter is for bubblesort 496

128 pass counters



counter is for bubblesort 8128



counter is for bubblesort 8128



counter is for bubblesort 8128

Abort trap: 6

*/
