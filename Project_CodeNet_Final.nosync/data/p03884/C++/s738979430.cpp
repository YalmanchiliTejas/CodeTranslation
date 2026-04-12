#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int L = 470;
ll dp[L][8];

int main() {
	ll k; cin >> k;
	dp[0][0] = 1;

	for (int i = 1; i < L; ++i) {
		for (int j = 0; j <= 7; ++j) {
			for (int k = j; k <= 7; ++k) {
				dp[i][k] += dp[i-1][j];
			}
		}
	}

	vi vec;
	for (int i = L-1; i >= 1; --i) {
		int num = k / dp[i][7];
		vec.pb(num);
		k %= dp[i][7];
	}

	reverse(ALL(vec));
	string ans;
	for (int x : vec) {
		ans += "FESTIVA";
		rep(i, x) ans.pb('L');
	}
	cout << ans << endl;

	return 0;
}