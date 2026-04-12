#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

int n;
ll a[MAXN],dp[MAXN];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	ll sum = a[1];
	for(int i = 2;i <= n;i++){
		if(i & 1){
			sum += a[i];
			dp[i] = max(dp[i - 1],dp[i - 2] + a[i]);
		}else
			dp[i] = max(sum,dp[i - 2] + a[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}

