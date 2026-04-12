#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
using namespace std;
int n,K;
ll ans=0;
int read()
{
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int main()
{
	n=read();K=read();
	if(K==0) ans=(ll)n*n;
	else 
		for(int b=K+1;b<=n;b++)
			ans+=(n/b)*(b-K)+max(n%b-K+1,0);
	printf("%lld",ans);	
    return 0;
}

