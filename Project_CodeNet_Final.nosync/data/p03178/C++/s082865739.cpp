#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	string S;
	cin >> S;
	int D;
	cin >> D;
	int N = S.size();

	ll mod = 1e9 + 7;
	ll dp1[10001][101] = {};
	ll dp2[10001][101] = {};
	dp1[0][0] = 1;

	rep(i, N) {
		int C = S[i] - '0';

		rep(j, 10) {
			if (j < C) {
				rep(k, D) {
					dp2[i + 1][(j + k) % D] += dp1[i][k];
					dp2[i + 1][(j + k) % D] %= mod;
				}
			}
			if (j == C) {
				rep(k, D) {
					dp1[i + 1][(j + k) % D] += dp1[i][k];
					dp1[i + 1][(j + k) % D] %= mod;
				}
			}
			rep(k, D) {
				dp2[i + 1][(j + k) % D] += dp2[i][k];
				dp2[i + 1][(j + k) % D] %= mod;
			}
		}
	}

	co((dp1[N][0] + dp2[N][0] - 1 + mod) % mod);

	Would you please return 0;
}