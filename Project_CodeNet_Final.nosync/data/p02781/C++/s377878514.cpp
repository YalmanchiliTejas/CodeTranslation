#define _USE_MATH_DEFINES // M_PI
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define rREP(i,a,n) for(int (i)=(n)-1; (i)>=(a);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 2147483647;
constexpr ll mod = 1000000007;

template<class T>inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void init() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

string N;
int K;

int dp[1000][2][4];
int rec(int k = 0, bool tight = true, int sum = 0) {
	if (sum > K)return 0;
	if (k == N.size())return sum == K;

	int x = N[k] - '0';
	int r = (tight ? x : 9);

	int& res = dp[k][tight][sum];
	if (~res)return res;
	res = 0;

	rep(i, r + 1) {
		res += rec(k + 1, tight && i == r, sum + (i != 0));
	}
	return res;
}

int main() {
	init();

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	cout << rec() << "\n";

	return 0;
}