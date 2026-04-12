#include<iostream>
using namespace std;
int main()
{
int n,sum;
cin>>n;
sum=n*800;
if(n>=1&&n<=100)
while(n-15>=0)
{
	sum-=200;
	n=n-15;
}
cout<<sum;
}