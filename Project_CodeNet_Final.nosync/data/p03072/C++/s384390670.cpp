#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn =1e4+100;
int n,m,res;

int a[maxn];
int mx=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=mx) mx=a[i],res++;
	}
	cout<<res<<endl;
	return 0;
}