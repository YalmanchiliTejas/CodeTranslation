#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#define pa pair<int,int>
#define INF 0x3f3f3f3f
#define inf 0x3f
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

inline ll read()
{
	long long f=1,sum=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')	f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll ans=0;
	if (!k)
	{
		cout<<(ll)n*n;
		return 0;
	}
	for (int b=k+1;b<=n;b++)
	{
		int t=n/b;
		ans+=(b-k)*t;
		int l=n-b*t;
		ans+=max(0,l-k+1);
	}
	cout<<ans;
	return 0;
}
