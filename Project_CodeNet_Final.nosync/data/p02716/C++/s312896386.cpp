#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
#define INF  0x7f7f7f7f//7f7f7f7f
#define M 2000010
#define N 100010
const ll mod = 1e9 + 7;
ll a[M],dp[M],sum[M],n;
int main(void){
	scanf("%lld",&n);
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		if(i%2)
		sum[i] =sum[i-1]+a[i];
		else
		sum[i] =sum[i-1];
	}
	for(ll i = 2;i <= n;i++){
		if(i%2)
		dp[i] =max(dp[i-2]+a[i],dp[i-1]);
		else
		dp[i] =max(dp[i-2]+a[i],sum[i-1]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}