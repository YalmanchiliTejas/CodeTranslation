#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()

void solve();

signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;    
    int tt = t;
    while (t--) { 
        solve();
    }
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
    return 0;
}
string s;
int k;
int dp[105][5][2] = {{{0}}};
void solve() {
	cin >> s;
	int n = (int) s.size();
	cin >> k;
	dp[0][0][0] = 1;
	s = '$' + s;
	for (int i = 1; i <= n; i++) {
		for (char here = '0'; here <= '9'; ++here) {
			for (int done = 0; done < 2; ++done) {
				if (!done and here > s[i])
					continue;
				for (int cnt = 0; cnt <= k; ++cnt) {
					int new_cnt = cnt;
					if (here != '0')
						++new_cnt;
					int new_done = done;
					if (!done and here < s[i])
						new_done = 1;
					dp[i][new_cnt][new_done] += dp[i - 1][cnt][done];
				}
			}
		}
	}
	cout << dp[n][k][0] + dp[n][k][1];
}   