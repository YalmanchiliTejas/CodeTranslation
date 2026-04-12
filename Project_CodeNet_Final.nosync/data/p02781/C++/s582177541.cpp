#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(int (i)=(n)-1; (i)>=(m);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 1000000001;
constexpr ll mod = 1000000007;
constexpr double PI = 3.1415926535897932;

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
int dp[101][2][4];

int rec(int k = 0, bool is = true, int sum = 0) {
	if (K < sum)return 0;
	if (k == N.size())return sum == K;

	int x = N[k] - '0';
	int r = (is ? x : 9);

	int& res = dp[k][is][sum];
	if (~res)return res;
	res = 0;

	rep(i, r + 1) {
		res+=rec(k + 1, is && i == x, sum + (i!=0));
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