#include <bits/stdc++.h>
#define MAXN 10010
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int a[MAXN], n, d, mod = 1e9 + 7;
ll dp[MAXN][2][110];

ll go(int x, bool b, int m){	//using digits x-(n-1), how many ways to sum to m
	if(dp[x][b][m] != -1) return dp[x][b][m];
	if(x == n) return m == 0;
	ll t = 0;
	if(b){
		for(int i = 0; i < a[x]; i++){
			t += go(x + 1, 0, (d + m - i) % d);
		}
		t += go(x + 1, 1, (d + m - a[x]) % d);
	} else{
		for(int i = 0; i <= 9; i++){
			t += go(x + 1, b, (d + m - i) % d);
		}
	}
	return dp[x][b][m] = t % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++){
		a[i] = s[i] - '0';
	}
    cin >> d;
    cout << (go(0, 1, 0) - 1 + mod) % mod;
}