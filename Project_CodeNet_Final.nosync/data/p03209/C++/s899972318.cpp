#include <bits/stdc++.h>
using namespace std;

long long pow(long long a,int b)
{
	if (b==0)
	{
		return 1LL;
	}
	long long ans=pow(a,b/2);
	ans*=ans;
	if (b%2==1)
	{
		ans*=a;
	}
	return ans;
}

long long my(int n,long long x)
{
	if (n==0)
	{
		return x;
	}
	if (x==1)
	{
		return 0LL;
	}
	long long a=pow(2LL,n+1)-3LL;
	if (x<=a+1LL)
	{
		return my(n-1,x-1);
	}
	else if (x==a+2LL)
	{
		return my(n-1,a)+1LL;
	}
	else if (x==a*2LL+3LL)
	{
		return my(n-1,a)*2LL+1LL;
	}
	else
	{
		return my(n-1,a)+1LL+my(n-1,x-a-2LL);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	long long x;
	cin>>n>>x;
	cout<<my(n,x)<<endl;
	return 0;
}
