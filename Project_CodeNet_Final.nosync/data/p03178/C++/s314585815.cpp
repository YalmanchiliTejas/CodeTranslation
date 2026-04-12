#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
template<class T> using pq = priority_queue<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -MOD * MOD;
const long double pi = 3.141592653589793;
int main() { // 問題文はしっかり読め!!!
	string s;
	cin >> s;
	int d;
	cin >> d;
	int n = s.size();
	VVV dp(n + 1, VV(2, V(d, 0))); // i桁目まで見て、その桁までsぴったりかのフラグで、桁和をdで割った余りがkになるもの
	dp[0][0][0] = 1;
	rep(i, n) {
		rep(j, 2) { // ここはnjが0ならばぴったりで、1ならばぴったりではないことを表す
			rep(k, d) {
				rep(num, 10) {
					int nj = j;
					if (nj == 0) {
						if (s[i] - '0' < num) continue;
						if (s[i] - '0' > num) nj = 1;
					}
					dp[i + 1][nj][(k + num) % d] += dp[i][j][k];
					dp[i + 1][nj][(k + num) % d] %= MOD;
				}
			}
		}
	}
	ll ans = (MOD - 1 + dp[n][0][0] + dp[n][1][0]) % MOD;
	cout << ans << endl;
	return 0;
}