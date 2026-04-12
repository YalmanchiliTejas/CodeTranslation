#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

int n, m, k;
int d[16], drev[105];
int v[105][105];
int dp[1 << 16];

const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	rep(i, 0, 1 << 16) dp[i] = INF;
	rep(i, 0, 105) drev[i] = -1;

	read(n, m, k);
	rep(i, 0, m) read(d[i]), drev[d[i]] = i;
	rep(i, 1, n + 1) rep(j, 0, k) read(v[i][j]);

	queue<int> Q;
	dp[(1 << m) - 1] = 0;
	Q.push((1 << m) - 1);
	
	while (!Q.empty()) {
		int st = Q.front(); Q.pop();
		rep(i, 0, k) {
			int nst = 0;
			vector<int> freq(m);
			rep(j, 0, m) if ((st & (1 << j)) && drev[v[d[j]][i]] != -1) {
				//write(i, d[j], "->", v[d[j]][i], "(", drev[v[d[j]][i]], ")");
				freq[drev[v[d[j]][i]]]++;
			}
			//for (auto p : freq)
			//	write(i, "F", p.first, p.second);
			rep(j, 0, m) if (freq[j]) nst |= 1 << j;
			//write(i, bitset<2>(st), "->", bitset<2>(nst));
			if (chmin(dp[nst], dp[st] + 1)) {
				Q.push(nst);
			}
		}
	}

	write(dp[0]);
}

