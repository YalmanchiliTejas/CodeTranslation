#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef vector < vector <int> > matrix;

int n, d, dp[10007][107][2];
string s;
const int mod = 1e9 + 7;

void add(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	cin >> d;
	n = (int)s.length();
	dp[0][0][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < d; j++){
			for(int dg = 0; dg <= 9; dg++){
				add(dp[i][(j + dg) % d][0], dp[i - 1][j][0]);
				if(dg > s[i - 1] - '0') continue;
				add(dp[i][(j + dg) % d][(dg == s[i - 1] - '0') ? 1 : 0], dp[i - 1][j][1]);
			}
		}
	}
	cout << (dp[n][0][1] + dp[n][0][0] - 1 + mod) % mod;
}
