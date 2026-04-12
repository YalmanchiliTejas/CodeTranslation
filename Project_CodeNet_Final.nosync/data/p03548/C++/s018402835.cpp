#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x,y,z;
int main()
{
 cin>>x>>y>>z;
 cout<<int((x-z)/(y+z))<<endl;
 return 0;
}