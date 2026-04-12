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

const int MN = 3010;

ll dp[MN][MN];

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];

	for (int l = 1; l <= N; ++l) {
		for (int i = 0; i <= N - l; ++i) {
			int j = i + l - 1;
			if (l == 1) {
				dp[i][j] = a[i];
			} else {
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
			}
		}
	}

	cout << dp[0][N-1] << endl;

	return 0;
}