#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;int x,y;
if(n<15)
{

x=800*n;
y=0;
}
else
{
x=800*n;
y=200*(n/15);
}
int z=x-y;
cout<<z;
}
