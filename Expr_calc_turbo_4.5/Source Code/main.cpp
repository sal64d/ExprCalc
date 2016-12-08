#include "expr_int.h"
#include "expr_float.h"
#include <conio.h>
#include "stack.h"


using namespace std;

int main(){

	cout << "Expresion Calculator 2000" << endl
         << "choose precision([int]->0, [float]->1): \n>> ";
	int c; 
	c=getch();

	cout << endl << endl;
    
	if(c-48){
		expr_float();
	}
	else{
		expr_int();
	}
    
	return 0;
}

/*#include <iostream>
#include "operand.h"
#include "stack.h"
#include <math.h>

using namespace std;

#ifndef expr_int_h
#define expr_int_h

int expr_int(){
    
	cout << "Enter a Numeric Expression ( May include integers,(),*,/,%,^,-,+ ).";
	while(true){
        
        int MAXLEN(200);
        char* raw(new char[MAXLEN]);           // creating a char Array to 
        cout << "\n[int]> ";                   // store user input

        cin.getline( raw , MAXLEN-1 , '\n' );  // taking input from user
        if(!strnlen(raw,MAXLEN)){              // Quit if no input
            return 0;
        }

        stack<int> postfix;                    // creating a int stack
        stack<operand> opd;                    // creating an operand stack

        opd.push_back(operand(-1,'('));        // Pushing an opening bracket

        bool error(0);                         // an error flag
        
        /* Following loop converts Expression to 
         * postfix and calculates it: /
        for( int i=0, iflag(0); i<=strlen(raw) ; ++i ){
            
            //1. For a Literal
            if((int)(raw[i])-48 >= 0 && (int)(raw[i])-48 <= 9){
                if(iflag){
                    int a =(int)(raw[i])-48 + postfix.pop_out() * 10;
                    postfix.push_back(a);
                } else{
                    iflag=1;
                    int a =(int)(raw[i])-48;
                    postfix.push_back(a);
                }
            } 
            
            //2. For an Operand
            else if(raw[i] == '(' || raw[i] == ')' || 
                    raw[i] == '*' || raw[i] == '/' || 
                    raw[i] == '%' || raw[i] == '-' || 
                    raw[i] == '+' || raw[i] == '^' || 
                    raw[i] == ' ' || raw[i] == '\0'){
                
                iflag=0;    //
                int poco;   // Operand priority flag
                
                // Sets operand priority flag
                switch(raw[i]){ 
                    case '+':case '-':poco=1;break;
                    case '*':case '/':case '%':poco=2;break;
                    case '^':poco=3;break;
                    case ')':poco=-2;break;
                    case '(':poco=-1;break;
                    default: poco=0;break;
                }
                
                operand dob(poco,raw[i]);   // New Operand type
                
                // priority of last operand in stack is smaller 
                if( (dob > 0 && dob >= opd.top()) || dob == -1 ){
                    opd.push_back(dob);
                }
                
                // priority of last operand in stack is larger
                else if( dob > 0 && dob <  opd.top()){
                    
                    // Gets the last operand in stack
                    operand poped(opd.top().p, opd.top().o);
                    
                    // Pop until last operand in stack is of smaller priority
                    while(dob < poped){
                        
                        opd.pop_out();  // Delete the last operand
                        
                        int b = postfix.get(postfix.size());  // Gets the last two 
                        int a = postfix.get(postfix.size()-1);  // Numbers form Postfix 
                                                            // Stack to work upon
                        
                        int r(1);                           // result variable
                        
                        postfix.pop_out();     // Clear the last two 
                        postfix.pop_out();     // Number in Postfix
                        
                        // Work upon the Numbers
                        switch(poped.o){
                            case '+':r=a+b;break;
                            case '-':r=a-b;break;
                            case '*':r=a*b;break;
                            case '/':r=a/b;break;
                            case '%':r=a%b;break;
                            case '^':for(int i(0); i<b; i++)r*=a;break;
                            default: r=a+b;break;
                        }
                        
                        // Push the result back in postfix stack
                        postfix.push_back(r);
                        
                        // Get the next operand in stack
                        poped(opd.top().p, opd.top().o);
                    }
                    
                    // Now push opernad in stack
                    opd.push_back(dob);
                }
                
                // operand is a closing bracket
                else if(dob == -2 || dob.o == '\0'){
                    
                    // Same as above, only that it pops operands
                    // until an opening bracket is found
                    operand poped(opd.top().p, opd.top().o);
                    while(poped != -1){
                        opd.pop_out();
                        int b = postfix.get(postfix.size());
                        int a = postfix.get(postfix.size()-1);
                        int r(1);
                        postfix.pop_out();
                        postfix.pop_out();
                        switch(poped.o){
                            case '+':r=a+b;break;
                            case '-':r=a-b;break;
                            case '*':r=a*b;break;
                            case '/':r=a/b;break;
                            case '%':r=a%b;break;
                            case '^':for(int i(0); i<b; i++)r*=a;break;
                            default: r=a+b;break;
                        }
                        postfix.push_back(r);
                        poped(opd.top().p, opd.top().o);
                    }
                    opd.pop_out();
                }

            }
            
            //3. An Error
            else{
                error=1;
                std::cout << "-> Invalid String" << endl;
                break;
            }
        }
        
        if(!error)                             // Printing Answer of Expression 
            cout << "=> Answer: "              // if No error is present
                 << postfix.top();
        
        postfix.clear();                       //Clearing the stacks for next run
        opd.clear();                              
        
        cout << endl;                          //Now Ready for another expression
	
	}
	return 0;
}

#endif*/