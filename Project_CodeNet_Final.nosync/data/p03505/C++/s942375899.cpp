#include<bits/stdc++.h>
using namespace std;
long long k,a,b,tian;
int main()
{
	cin>>k>>a>>b;
	if(a>=k)
	{
		cout<<1<<endl;
		exit(0);
	}
	if(a<=b)
	{
		cout<<-1<<endl;
		return 0;
	}
	if((k-a)%(a-b)>=1) tian=1;
	cout<<((k-a)/(a-b)+tian)*2+1<<endl;
	
	}