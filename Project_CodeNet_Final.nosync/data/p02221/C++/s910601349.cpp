#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

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

const int maxn = 18;

int winner[1 << 18][maxn + 1];

int main() {
	int N; cin >> N;
	string S; cin >> S;
	V<int> P(1 << N);

	rep(i, (1 << N)) {
		cin >> P[i];
	}

	rep(i, (1 << N)) {
		winner[i][0] = P[i];
	}

	for (int k = 1; k <= N; ++k) {
		rep(l, (1 << N)) {
			int x = winner[l][k-1];
			int r = ((1 << (k-1)) + l) % (1 << N);
			int y = winner[r][k-1];
			if (x > y) swap(x, y);
			if (S[y-x-1] == '0') {
				winner[l][k] = x;
			} else {
				winner[l][k] = y;
			}
		}
	}

	rep(i, 1 << N) {
		printf("%d\n", winner[i][N]);
	}
	return 0;
}
