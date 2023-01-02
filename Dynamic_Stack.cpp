//Program to implement stack using dynamic array.

#include<iostream>
using namespace std;

class IntStack 
{
    private:
	    int size=5;
	    int top=0;
	    int *stack = new int(size);

    public:
	    bool empty()
	    {
	        if(top == 0)
	            return true;
	        else
	            return false ;
	    }
	
	    bool full()
	    {
	        if(top >= size)
	            return true;
	        else 
	            return false ;
	    }
	    
	    void changeArray(int newSize)
	    {
	        int *arr2 = new int(newSize);
	        for(int i=0;i<size;i++)
	        {
	            arr2[i] = stack[i];
	        }
	        delete(stack);
	        stack = arr2;
	        size = newSize;
	    }
	    
	    int push(int item)
	    {
	        if(full())
	        {
	            changeArray(2*size);
	            push(item);
	            return 0;
	        }
	        else
	        {
	             stack[top]=item ;
	             top++;
	             return 1 ;
	        }
	    }
	
	    int pop()
	    {
	        if(!empty()) 		//i.e. stack not empty
	        {
	        	cout<<"The popped element is "<< stack[top]<<endl;
	            top = top - 1;
	            return stack[top];
	        }
	        else
	        {
	            cout<<"\nStack is empty !! Nothing to pop in stack!";
	            exit(-1);
	        }
	    }
	
	    void printStack()
	    {
	    	cout<<"\nElements of stack are : ";
	        for (int i = 0; i < top ; i++)
	        {
	            cout << stack[i] <<" ";
	        }
	        cout << "\n";
	    }
};

int main()
{
   IntStack is;
   int choice, value;
   cout<<"|----------------------------------------|"<<endl;
   cout<<"|         1. Push in stack               |"<<endl;
   cout<<"|         2. Pop from stack              |"<<endl;
   cout<<"|         3. Display stack               |"<<endl;
   cout<<"|         4. Exit                        |"<<endl;
   cout<<"|----------------------------------------|"<<endl;
   do 
   {
      cout<<"\nEnter choice: ";
      cin>>choice;
      switch(choice) 
	  {
         case 1: 
		 {
            cout<<"\nEnter value to be pushed: ";
            cin>>value;
            is.push(value);
            break;
         }
         case 2: 
		 {
            is.pop();
            break;
         }
         case 3: 
		 {
            is.printStack();
            break;
         }
         case 4: 
		 {
            cout<<"Exit"<<endl;
            break;
         }
         default: 
		 {
            cout<<"\nInvalid Choice"<<endl;
            break;
         }
      }
   }while(choice!=4);
   
   return 0;
 }



