#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    char x;int i,a=0,b=0;
    for(i=0;i<3;i++)
    {
        scanf("%c",&x);
        if(x=='A') a++;
        else if(x=='B') b++;
    }
    if(a&&b) printf("Yes");
    else printf("No");
}
