#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007

ll p[60], s[60], N, X;

ll bu(ll N,ll X) {
	if (N == 0 and X == 1)return 1;
	if (X <= 1)return 0;
	if (X == s[N]) return p[N];
	ll ans = 0;
	X--;
	ans += bu(N - 1, min(s[N - 1], X));
	X -= s[N - 1];
	if (X > 0) {
		X--;
		ans++;
		ans += bu(N - 1, min(s[N - 1], X));
	}
	return ans;
}
int main() {
	p[0] = 1;
	s[0] = 1;
	cin >> N >> X;
	REP(i, N)p[i + 1] = p[i] * 2 + 1;
	REP(i, N)s[i + 1] = s[i] * 2 + 3;
	cout << bu(N, X) << endl;
}

