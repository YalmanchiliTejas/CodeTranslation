#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){

int n,r;
string st;
while(1){
cin>>st;
if(st=="#")break;
int side=0,side2=0;int c=0;
for(int i=0;i<st.size();i++)
{
	if(st[i]=='a')side2=0;if(st[i]=='s')side2=0;if(st[i]=='d')side2=0;if(st[i]=='f')side2=0;
if(st[i]=='z')side2=0;if(st[i]=='x')side2=0;if(st[i]=='c')side2=0;if(st[i]=='v')side2=0;
if(st[i]=='q')side2=0;if(st[i]=='w')side2=0;if(st[i]=='e')side2=0;if(st[i]=='r')side2=0;
if(st[i]=='t')side2=0;if(st[i]=='g')side2=0;if(st[i]=='b')side2=0;

if(st[i]=='y')side2=1;if(st[i]=='h')side2=1;if(st[i]=='m')side2=1;
if(st[i]=='u')side2=1;if(st[i]=='j')side2=1;if(st[i]=='n')side2=1;
if(st[i]=='i')side2=1;if(st[i]=='k')side2=1;if(st[i]=='p')side2=1;
if(st[i]=='o')side2=1;if(st[i]=='l')side2=1;

if(i>0&&side2!=side)c++;
side=side2;

}
cout<<c<<endl;

}
return 0;
}