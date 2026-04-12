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

const ll MOD = 1000000007;

int N;
int A, B, C, D;
ll dp[1010];
ll comb[1010][1010];
ll t[1010][1010];

inline void add(ll &x, ll y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	rep(i, 1010) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
		}
	}

	cin >> N >> A >> B >> C >> D;
	dp[0] = 1;

	for (int i = A; i <= B; ++i) {
		t[i][0] = 1;
		for (int j = 1; j * i <= N; ++j) {
			t[i][j] = t[i][j-1] * comb[i * j - 1][i - 1] % MOD;
		}

		for (int j = N; j >= 0; --j) {
			if (dp[j] > 0) {
				for (int k = C; k <= D; ++k) {
					int nj = j + i * k;
					if (nj > N) {
						break;
					}
					add(dp[nj], dp[j] * comb[nj][j] % MOD * t[i][k] % MOD);
				}
			}
		}
	}

	cout << dp[N] << endl;

	return 0;
}