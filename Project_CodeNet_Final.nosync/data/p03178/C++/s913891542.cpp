#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const ll MOD = 1e9 + 7;

ll DP[10010][101][10];

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	string s;
	int d;
	cin >> s >> d;
	int n = s.size();
		
	M00(dig, 10) {
		M00(i, d) {
			DP[1][i][dig] = (dig % d == i) ? 1 : 0;
		}
	}
	for(int len = 2; len <= n; len++) {
		M00(dig, 10) {
			M00(i, d) {
				int next = (i - dig) % d;
				next += d;
				next %= d;
				M00(dig2, 10) {
					DP[len][i][dig] += DP[len-1][next][dig2];
					DP[len][i][dig] %= MOD;
				}
			}
		}
	}
	/*
	M00(i, n) {
		M00(j, 10) {
			M00(k, d) {
				cout << DP[i+1][k][j] << " ";
			}
			cout << endl;
		}
	}
	*/

	int cur = 0;
	ll ans = 0;
	M00(i, n) {
		M00(j, s[i] - '0') {
			ans += DP[n - i][cur][j];
			ans %= MOD;
		}
		cur -= s[i] - '0';
		cur %= d;
		cur += d;
		cur %= d;
	}
	if(cur == 0) ans++;
	ans--;
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}
