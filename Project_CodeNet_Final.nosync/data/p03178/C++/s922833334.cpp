#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ppp pop_back
#define pii pair<int,int>
#define fi first
#define se second

const int N = 1e4 + 5;
const int p = 1e9 + 7;
const int D = 105;

int dp[N][10][D];
int total[N][D];
int a[N];

void add(int &a, int b) {
	a += b;
	if (a >= p) a -= p;
	if (a < 0) a += p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
	string s;
	int d;
	cin >> s >> d;
	int n = s.length();
	for (int i=0; i<N; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<D; k++) {
				dp[i][j][k] = 0;
				total[i][k] = 0;
			}
		}
	}
	for (int i=0; i<10; i++) {
		dp[1][i][i % d]++;
		total[1][i % d]++;
	}
	for (int i=2; i<=n; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<d; k++) {
				dp[i][j][k] = total[i-1][((k-j)%d + d)%d];
                add(total[i][k], dp[i][j][k]);
			}
		}
	}
	reverse(s.begin(), s.end());
	s = '$' + s;
	for (int i=1; i<=n; i++) a[i] = s[i] - '0';
	int ans = total[n][0];
	int cur = 0;
	for (int i=n; i>=1; i--) {
		for (int j=a[i]+1; j<10; j++) {
			add(ans, -dp[i][j][(d - cur) % d]);
		}
		cur = (cur + a[i]) % d;
	}
	add(ans, -1);
	cout << ans << "\n";
    return 0;
}
