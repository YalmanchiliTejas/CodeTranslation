#include<cstdio>
#include<iostream>
using namespace std;
char ans[100010],spe[100010];
int n;
bool c(char l)
{
switch(l)
{
case 'o':return true;
case 'x':return false;
case 'S':return true;
case 'W':return false;
}
}
char c(bool l){return (l?'S':'W');}
char func(int i,int j)
{return (c((c(spe[i])==c(ans[i]))==(c(spe[j]))));}
bool comp(char f,char s)
{
int i;
spe[0]=f;spe[1]=s;
for(i=2;i<n;i++)
{spe[i]=func(i-1,i-2);}
return (func(n-1,n-2)==spe[0]&&func(0,n-1)==spe[1]);
}
int main()
{
cin>>n>>ans;
if(comp('S','S'))
{cout<<spe;return 0;}
if(comp('S','W'))
{cout<<spe;return 0;}
if(comp('W','S'))
{cout<<spe;return 0;}
if(comp('W','W'))
{cout<<spe;return 0;}
cout<<"-1";
return 0;
}
