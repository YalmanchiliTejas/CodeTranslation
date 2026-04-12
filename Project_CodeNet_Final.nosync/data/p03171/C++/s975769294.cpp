#include<bits/stdc++.h>
using namespace std;
int N;
long long f[3005][3005],a[3005];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	   scanf("%lld",&a[i]);
	for(int i=1;i<=N;++i)
	{
		int s=N-i+1; 
		for(int j=1;j<=s;++j)
		{
			if(s%2==1) f[j][j+i-1]=max(f[j+1][j+i-1]+a[j],f[j][j+i-2]+a[j+i-1]);
			else f[j][j+i-1]=min(f[j+1][j+i-1]-a[j],f[j][j+i-2]-a[j+i-1]);
		}
	}
	printf("%lld\n",f[1][N]);
	return 0;
}