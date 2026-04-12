#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=3007;

ll dp[N][N],a[N];

int main(){
	int n=input();
	for(int i=1;i<=n;i++) a[i]=input();

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int l=j-i+1,r=j;
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	printf("%lld\n",dp[1][n]);
}