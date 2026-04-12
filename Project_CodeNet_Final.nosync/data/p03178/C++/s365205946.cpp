#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define MOD 1000000007
using namespace std;
char str[10001];
int d,f[10001][100],len,limited[10001],remain[10001];
long long ans;
int main()
{
	scanf("%s",str);
	scanf("%d",&d);
	len=strlen(str);
	limited[0]=1;remain[0]=0;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<d;j++)
			for(int l=0;l<10;l++)
				f[i+1][(j+l)%d]=(f[i+1][(j+l)%d]+f[i][j])%MOD;
		for(int j=0;j<str[i]-'0';j++) f[i+1][(remain[i]+j)%d]=(limited[i]+f[i+1][(remain[i]+j)%d])%MOD;
		limited[i+1]=limited[i]; remain[i+1]=(remain[i]+str[i]-'0')%d;
	}
	ans=f[len][0]-1;
	if(!remain[len]) ans++;
	ans=(ans+MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
