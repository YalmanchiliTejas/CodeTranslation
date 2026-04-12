#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a[100],b[100];
ll dfs(ll x,int y)
{
	if(x<=0)
	{
		return 0;
	}
	if(y==0)
	{
		return 1;
	}
	if(a[y]==x)
	{
		return b[y];
	}
	ll ans=0;//a[y]>x
	int i;
	if(x>=a[y-1]+1)//b ***** p ***** b
	{
		ans+=b[y-1];
		if(x>=a[y-1]+2)
		{
			ans++;
			if(x>a[y-1]+2)
			{
				x-=a[y-1]+2;
				for(i=0;i<y;i++)
				{
					if(a[i]+(y-i-1)>=x)
					{
						break;
					}
				}
				ans+=dfs(x-(y-i-1),i);
			}
		}
		return ans;
	}
	else
	{
		for(i=0;i<y;i++)
		{
			if(a[i]+(y-i)>=x)
			{
				break;
			}
		}
		return dfs(x-(y-i),i);
	}
}
int main()
{
	int i,j,k,n,x,y;
	ll m,an=1,aa=1;
	scanf("%d%lld",&n,&m);
	for(i=0;i<=n;i++)
	{
		a[i]=an;
		b[i]=aa;
		if(a[i]>=m)
		{
			break;
		}
		an=an*2+3;
		aa=aa*2+1;
	}
//	printf("%d",m-n+i);
	cout<<dfs(m-(n-i),i);
	return 0;
}