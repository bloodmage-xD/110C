/*
	class : 110c
	author = 'andrew'
	assigemt 6 i  think
  Infix to postfix conversion in C++ 

*/
#include<iostream>
#include<string>
#define max 100

std::string InfixToPostfix(std::string expression);

int compare(char operator1, char operator2);

bool IsOperator(char s);

bool IsOperand(char s);


template<typename T>
class Node{
	public:
	T data;
	Node<T> *next;
};
template<typename T>
class Stack {
	Node<T> *top;
	std::size_t  count; // holds number
	public:
		Stack() : count(0) {}
		void push(T d){
			if (count == max)
				throw "max size reached ";
			if (top == nullptr){
				Node<T> *newnode = new Node<T>;
				newnode->data = d;
				newnode->next = nullptr;
				top = newnode;
				count++;
			}
			else{
				Node<T>* newnode = new Node<T>;
				newnode->data = d;
				newnode->next = top;
				top = newnode;
				count++;

			}			
		} 
		void print() const{
			Node<T>* temp = top;
			while(temp != nullptr){
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		std::cout << std::endl;
		
	}
		void pop(){
			if (count== 0 )
				throw "nothing to pop ";
			else {
				Node<T> * newnode = new Node<T>;
				newnode = top;
				top = top->next;
				count--;
				delete newnode;
			}
		}
		std::size_t size() const{
			return count;
		}
		bool isempty() const {
			return (count == 0);
		} 
		T Top() const {
			return top->data;
		}
	//	~Stack(){
//			Node<T> *current = top;
//			Node<T> *temp = top;
//			while (temp != NULL){
//				Node<T> *next = current->next;
//				delete current;
//				current = next;
//			}
//		}
		
};

int  eval(int op1, int op2, char operate){
	switch(operate){
		case '+':
			return op1 + op2;
			
		case '-':
			return op1 - op2;
			
		case '/':
			return  op1 / op2;
			
		case '*':
			return op1 * op2;
	
	}
}

int calculate(std::string expression){
	char hold;
	int result;
	Stack<int> s;
	int i = 0;
	for (; i < expression.length(); i++){
		hold = expression[i];
		if (isdigit(hold))
			s.push(i);
		else{
			int op1 = s.Top();
			s.pop();
			int op2 = s.Top();
			s.pop();
			result = eval(op1, op2, hold);
		}
		i++;
	}
	

}


// Function to evaluate Postfix expression and return output
std::string InfixToPostfix(std::string expression)
{ 
	Stack<char> S;
	std::string postfix = ""; 
	for(int i = 0; i< expression.length(); i++) {


		if(IsOperator(expression[i])) 
		{
			while(!S.isempty() && S.Top() != '(' && compare(S.Top(),expression[i]))
			{
				postfix+= S.Top();
				S.pop();
			}
			S.push(expression[i]);
		}
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.isempty() && S.Top() !=  '(') {
				postfix += S.Top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.isempty()) {
		postfix += S.Top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char s) 
{
	if(s >= '0' && s <= '9') return true;
	if(s >= 'a' && s <= 'z') return true;
	if(s >= 'A' && s <= 'Z') return true;
	return false;
}

// Function to verify whether a character
bool IsOperator(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/')
		return true;

	return false;
}


//function gets rank of a operator
int crank(char op)
{
	int weight = 0; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;
}

// Function to perform an operation and return output. 
int compare(char op1, char op2)
{
	int op1rank = crank(op1);
	int op2rank = crank(op2);

	return op1rank > op2rank ?  true: false;
}

int main() 
{
        std::string expression; 
        std::cout<<"Enter Expression " << std::endl;
        std::cin >> expression;
        std::string postfix = InfixToPostfix(expression);
        std::cout <<"Output is  = "<<postfix << std::endl;
        
//	for (auto c : expression)
//		(int)c;
	Stack<int> stack;
	stack.push(8+5);
	stack.print();	
			
}
  
/*

Enter Expression 
8+5
Output is  = 85+
13

[amei3@hills ~]$ 



*/
