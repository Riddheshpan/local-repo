#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int pop();
int priority(char symbol);
int isempty();
void infix_to_prefix();
int check(char symbol);
void push(long int symbol);
char prefix_string[20],infix_string[20],post_fix[20];
int top;
long int stack[20];
int main()
{
    int count,size;
    char temp;
    top=-1;
    printf("\nEnter an expression in infix format:-\n");
    gets(infix_string);
    infix_to_prefix();
    printf("\nExpresion in postfix formate:-\t %s\n", post_fix);
    size=strlen(post_fix)-1;
    strcpy(prefix_string,post_fix);
    for (count = 0; count<size; count++,size--)
    {
        temp=prefix_string[count];
        prefix_string[count]=prefix_string[size];
        prefix_string[size]=temp;
    }
    printf("Expression in prefix formate:-\t%s\n",prefix_string);
    return 0;
}
void infix_to_prefix(){
    int count ,temp=0;
    char next;
    char symbol;
    for(count=0;count<strlen(infix_string);count++)
    {
        symbol=infix_string[count];
        if(!check(symbol)){
            switch (symbol)
            {
            case '(':
            push(symbol);
                break;
            case ')':
            while((next = pop())!='('){
                post_fix[temp++]=next;
            }
                break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'%':
            case'^':
            while (!isempty()&& priority(stack[top])>=priority(symbol))
            {
                post_fix[top++]=pop();
            }
            push(symbol);
            break;
            default:
            post_fix[temp++]=symbol;
                break;
            }
        }
    }
    while (!isempty())
    {
        post_fix[temp++]=pop();
    }
    post_fix[temp]='\0';   
}
int priority(char symbol){
    switch (symbol)
    {
    case'(':
    return 0;
    case'+':
    case'-':
    return 1;
    case'*':
    case'/':
    case'%':
    return 2;
    case'^':
    return 3;
    default:
    return 0;
    }
}
int check(char symbol){
    if(symbol=='\t'||symbol==' ')
        return 1;
    else
        return 0;
}
void push(long int symbol)
{
    if(top>20)
    {
        printf("Stack overflow");
        exit(1);
    }
    top=top+1;
    stack[top]=symbol;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int pop()
{
    if(isempty())
    {
        printf("Stack is Empty");
        exit(1);
    }
    return(stack[top--]);
}