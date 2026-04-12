#include<bits/stdc++.h>
using namespace std;

using ll = long long;

//constant
const ll MOD = 1e+9 + 7;
const double EPS = 1e-10;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(), (x).rend()

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

// view vector
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }

// DP
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// ***************************************

int main(void) {

	ll N;
	cin >> N;

	vector<vector<ll>> dp(N, vector<ll>(N));
	vector<ll> A(N);

	REP(i, N) {
		cin >> A[i];
	}

	ll end;
	int sign = (N % 2 == 1) ? 1 : -1;
	REP(i, N) {
		end = N - i;
		REP(j, end) {
			if (i == 0) dp[i][j] = sign * A[j];
			else {
				if (sign == 1) {
					dp[i][j] = max(A[j] + dp[i-1][j+1], A[j+i] + dp[i-1][j]);
				}
				else {
					dp[i][j] = min(-A[j] + dp[i-1][j+1], -A[j+i] + dp[i-1][j]);
				}
			}
		}
		sign *= -1;
	}

	cout << dp[N - 1][0] << endl;

	return 0;
}