#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
unsigned long long n,m,k,ans;
int main()
{
	cin>>n>>m>>k;
	if (m>n)
	{
		cout<<1;
		return 0;
	}
	if (m<=k)
	{
		if (m>=n)
		{
			cout<<1;
			return 0;
		}
		cout<<-1;
		return 0;
	}
	n-=m;
	ans=n/(m-k)*2;
	if (n%(m-k)!=0) ans+=2;
	ans++;
	cout<<ans;
	return 0;
}