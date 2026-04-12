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
	int K;
	cin >> K;
	int n = s.size();
	VVV dp(n + 1, VV(2, V(n + 1, 0)));
	dp[0][0][0] = 1;
	rep(i, n) {
		rep(j, 2) {
			rep(k, n) {
				rep(num, 10) {
					int zero = (num != 0);
					int nj = j;
					if (nj == 0) {
						if (s[i] - '0' < num) continue;
						if (s[i] - '0' > num) nj = 1;
					}
					dp[i + 1][nj][k + zero] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n][0][K] + dp[n][1][K] << endl;
	return 0;
}