#include<bits/stdc++.h>
#define st first
#define nd second 

using  namespace std;
using pii = pair<int, int>;
using ll = long long;
const  int N = 3e3 + 10;
const int mod = 998244353;
int dp[N];
int add(int a, int b){
	a += b;
	a %= mod;
	return a;
}
int main(){
	int n, k, x, ans = 0;
	scanf("%d %d",&n, &k);
	dp[0] = 1;
	for(int i =1; i <= n; i++){
		scanf("%d", &x);
		if(x <= k){
			for(int j = k; j >= x; j--){
				dp[j] = add(dp[j], dp[j - x]);
			}
		}
		dp[0]++;
		ans = add(ans, dp[k]);
	}
	printf("%d", ans);
}
