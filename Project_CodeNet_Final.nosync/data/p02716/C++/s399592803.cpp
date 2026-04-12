#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)>>1)
#define st first
#define nd second
#define ll long long
#define N 200005
#define inf 10000000000000000ll
#define MOD 1000000007
#define LOG 31
#define EPS 0.000000001
#define M 305
#define PI 3.14159265359
using namespace std;

int n;
int a[N], cnt[N][3];
ll dp[N][3]; // h - 1, h, h + 1

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int value = (i >> 1) - 1;
		for(int j = 0; j < 3; j++)
			cnt[i][j] = value + j;
	}
	dp[0][0] = dp[0][2] = -inf;
	for(int i = 1; i <= n; i++) {
		fill(dp[i], dp[i] + 3, -inf);
		for(int j = 0; j < 3; j++) {
			if(cnt[i][j] < 0) 
				continue ;
			for(int k = i; k >= 1; k--) {
				int prv = max(0, k - 2);
				if(cnt[prv][2] + 1 < cnt[i][j])
					break ;
				for(int z = 0; z < 3; z++) {
					if(cnt[prv][z] + 1 == cnt[i][j]) {
						dp[i][j] = max(dp[i][j], dp[prv][z] + a[k]);
					}
				}
			}
			if(cnt[i][j] == 0) 
				dp[i][j] = 0;
		}
	}
	cout << dp[n][1];

}