#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 3e5+1;
int n,a[N],b[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int x=n,tmp=2;
	for(int i=1;i<=n;++i)
	{
		b[i]=a[x];
		x-=tmp;
		if(!x)x=1;
		if(n%2&&x==3&&tmp==-2)x=2;
		if(x==1)tmp*=-1;
	}
	for(int i=1;i<=n;++i)cout<<b[i]<<" ";
}