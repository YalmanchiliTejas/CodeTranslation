#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const ll MOD = 1e9+7;
const bool debug = 0;

int N;
int d[212345];
ll sum[212345];

int main() {
	cin >> N;
	REP(i, N) scanf("%d", d + i);
	
	REP(i, N) sum[i + 1] = sum[i] + d[i];
	
	int ans = 0;
	map<ll, int> m;
	REP(i, N + 1) {
		if (!m.count(sum[i])) m[sum[i]] = i;
		if (m.count(sum[i])) chmax(ans, i - m[sum[i]]);
	}
	
	cout << ans << endl;
	
	return 0;
}