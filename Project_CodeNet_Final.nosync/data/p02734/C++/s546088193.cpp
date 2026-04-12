#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int mode = 998244353;
const int maxn = 3e3  + 7;
int dp[maxn],a[maxn];
int main()
{
	int n,s;
	cin >> n >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		dp[0]++;
		for(int j = s;j >= a[i];j--){
			dp[j] = (dp[j] + dp[j - a[i]]) % mode;
		}
		ans = (ans + dp[s]) % mode;
	}
	cout << ans << endl;
	return 0;
 } 