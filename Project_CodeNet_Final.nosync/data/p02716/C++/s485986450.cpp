#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
int n;
ll num[200005],f[200005][3],ans=-1e18;
ll b(int a){if(a&1)return 1;return 0;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	if(n%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][0]+b(i)*num[i];
			f[i][1]=max(f[i-1][1]+b(i-1)*num[i],f[i-1][0]);
		}
		printf("%lld",f[n][1]);
		
	}
	else
	{
		
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i-1][0]+b(i)*num[i];
			f[i][1]=max(f[i-1][1]+b(i-1)*num[i],f[i-1][0]);
			if(i>1)f[i][2]=max(f[i-2][2]+b(i-2)*num[i],f[i-1][1]);
			else f[i][2]=max(f[i-1][2]+b(i-2)*num[i],f[i-1][1]);
//			cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
		}
		printf("%lld",f[n][2]);
	}
	return 0;
} 