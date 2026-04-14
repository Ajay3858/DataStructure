#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch){
	if(top<MAX-1){
		stack[++top]=ch;
	}
}
char pop(){
	return stack[top--];
}
int isempty(){
return top==-1;
}
int peek(){
	return stack[top];
}
int precedence(char ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}
	else if(ch=='*'||ch=='/')
	{
		return 2;
	}
	return 0;
}
int main(){
	char infix[MAX],postfix[MAX];
	fgets(infix,MAX,stdin);
	int k=0;
	for(int i=0;infix[i]!='\0';i++){
		char ch=infix[i];
		
	if(ch==' '||ch=='\n'){
		continue;
	}
	else if (isalnum(ch)){
		postfix[k++]=ch;
		postfix[k++]=' ';
	}
	else if(ch=='('){
		push(ch);
	}
	else if(ch==')'){
		while(!isempty()&&peek()!='('){
			postfix[k++]=pop();
			postfix[k++]=' ';
		}
		pop();
	}
	else{
		while(!isempty()&&precedence(peek())>=precedence(ch)){
			postfix[k++]=pop();
			postfix[k++]=' ';
		}
		push(ch);
	}
}
while(!isempty()){
	postfix[k++]=pop();
	postfix[k++]=' ';
}
postfix[k]='\0';
printf("%s",postfix);
return 0;}