#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<map> 
#include<list>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#define ll long long
#define memset(a,n) memset(a,n,sizeof(a))
#define mp make_pair 
#define pb push_back
using namespace std;
const int maxn = 2e5 + 100;


int main()
{
	int n;int a[maxn];ll p[maxn];scanf("%d",&n);
	for(int i = 1 ;i <= n;i++) scanf("%d",&a[i]);
	p[1] = a[1];
	for(int i = 3;i <= n;i += 2){
		p[i] = p[i-2] + a[i];
	}
	ll dp[maxn] = {0};
	for(int i = 2; i <= n;i++){
		if(i & 1){
			dp[i] = max(dp[i-1],dp[i-2]+a[i]);
		}else{
			dp[i] = max(dp[i-2] + a[i],p[i-1]);
		}
	}
	printf("%lld\n",dp[n]);
}