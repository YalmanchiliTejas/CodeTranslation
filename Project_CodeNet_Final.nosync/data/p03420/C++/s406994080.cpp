#include<iostream>
using namespace std;
long n,k,cnt;
main()
{
	cin>>n>>k;
	for(long b=k+1;b<=n;b++)
	{
		cnt+=(b-k)*((n+1)/b)-(k==0);
		long B=(n+1)/b*b;
		if(B+k<=n)cnt+=n-(B+k)+1;
	}
	cout<<cnt<<endl;
}