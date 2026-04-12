#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k,a=0;
	for(int i=1;i<=3;i++)
	{
		cin>>k;
		a=a*10+k;
	 } 
	 if(a%4==0) cout<<"YES"<<endl;
	 else cout<<"NO"<<endl;
	 return 0;
}