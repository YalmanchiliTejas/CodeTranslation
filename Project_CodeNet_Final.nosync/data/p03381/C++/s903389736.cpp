#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define REP1(i,n) for(int i = 1; i <= (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define ALL(a) begin(a), end(a)
#define MP(a,b) make_pair((a), (b))
#define ROUNDUP(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))
#define X first
#define Y second
#define DEBUG(a) cout << #a << ": " << a << "\n"
// #define DEBUG(a) {}

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 1;
constexpr ll LLINF = 4 * 1e18 + 1;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

template<typename T>
T debug(T x) {
	DEBUG(x);
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vi a(n);
	REP(i, n) cin >> a[i];
	vi aa = a;
	sort(ALL(aa));
	REP(i, n){
		if(a[i] <= aa[n / 2 - 1]) cout << aa[n / 2] << "\n";
		else cout << aa[n / 2 - 1] << "\n";
	}
	return 0;
}
