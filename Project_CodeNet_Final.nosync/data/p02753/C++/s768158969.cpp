#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{char S[3];
int i,a=0,b=0;
for(i=0;i<3;i++)
{cin>>S[i];
if(S[i]=='A')
a++;
if(S[i]=='B')
b++;
}
if(a==3||b==3)
printf("No");
else
printf("Yes");
}