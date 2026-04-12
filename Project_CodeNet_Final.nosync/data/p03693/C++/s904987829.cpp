#include<stdio.h>
#include<iostream>
using namespace std;
  
int main(void)
{
int a,b,c;
cin>>a>>b>>c;
int d = 10*b+c;
if(d%4==0)
cout<<"YES";
else
cout<<"NO";
return 0;
}