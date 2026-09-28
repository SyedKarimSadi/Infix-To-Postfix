#include<iostream>
#include<string>
using namespace std;

class Node{
public: 
    char data;
    Node* next;
Node(char ch){
    data=ch;
    next=NULL;
}
};
class Stack{
private:
    Node* Top;
public:
    Stack(){
        Top=NULL;
    }
bool isEmpty(){
    return (Top==NULL);
}
void push(char ch){
    Node* newNode=new Node(ch);
    newNode->next=Top;
    Top=newNode;
}
char Pop(){
    if(isEmpty()){
        return '#';
    }
    char ch=Top->data;
    Node* temp=Top;
    Top=Top->next;
    delete temp;

    return ch;
}
char Peek(){
    if(isEmpty()){
        return '#';
    }
    return Top->data;
}
};
bool isOperand(char token){
 return ( (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') ||
        (token >= '0' && token <='9') );
}

bool isOperator(char token){
 return ( token=='^' || token=='*' || token=='/' || token=='%' || token=='+' ||
   token=='-' || token=='(' || token==')');
}

bool isLeftAssociative(char token){
 return (  token=='*' || token=='/' || token=='%' || token=='+' || token=='-' );
}

int priority(char token){
if (token == '^')
    return 3;
if (token == '*' || token == '/' || token == '%')
    return 2;
if (token == '+' || token == '-')
    return 1;
else
    return 0;
}

string infixToPostfix(string infix){
    if ( infix == "" ) return "";
string postfix = ""; Stack stk;

for (int i=0; i<infix.length(); i++){
    char token = infix[i];
    if (token == ' ') continue;
    // operands:
    if (isOperand(token)){
        postfix += token;
    }
    //operators:
    else if ( isOperator(token) ){
        if ( token == '('){
                    stk.push(token);
            }
        else if ( token == ')'){
            while ( !stk.isEmpty() && stk.Peek()!= '(')
                postfix  += stk.Pop();
             if (!stk.isEmpty()) stk.Pop();
        }else {
            while ( !stk.isEmpty() &&
                   ( (isLeftAssociative(token) && priority(stk.Peek()) >= priority(token))
                   ||
                   (!isLeftAssociative(token) && priority(stk.Peek()) > priority(token) ) )
                   )
                        postfix += stk.Pop();

            stk.push(token);
        }
    } 
}

while ( !stk.isEmpty() )
    postfix += stk.Pop();
return postfix;
}

int main()
{
    string infix = "", postfix = "";
    cout<<"\n enter infix expression = ";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    if (postfix != "")
        cout<<"\n postfix = "<<postfix<<endl<<endl;
    return 0;
}