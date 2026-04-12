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
long long n,m,i,j,ans;
int main()
{
	cin>>n>>m;
	if (m==0)
	{
		cout<<sqr(n);
		return 0;
	}
	for (i=m+1;i<=n;i++)
	{
		long long x=i-m;
		ans+=n/i*x;
		if (n%i>=m) ans+=n%i-m+1;
	}
	cout<<ans;
	return 0; 
}