#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int a,b,c,d,i,j,k;
vector<long long int>v;
cin>>a;
for(i=1;i<=a;i++)
{
cin>>b;
v.push_back(b);
}
for(i=a-1;i>=0;i-=2)
{
cout<<v[i]<<" ";
}
if(a%2==0)
{
for(i=0;i<a;i+=2)
{
cout<<v[i]<<" ";
}
}
else
{
for(i=1;i<a;i+=2)
{
cout<<v[i]<<" ";}}
}