#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
template <typename A, typename B> inline bool chmax(A &a, B b) {if (a < b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline bool chmin(A &a, B b) {if (a > b) {a = b; return 1;} return 0;}
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const bool debug = 0;
/****************************/


int main(){
	int n, l, r;
	int a[50];
	while (cin >> n >> l >> r, n || l || r) {
		REP(i, n) scanf("%d", a + i);
		
		int ans = 0;
		
		FOR(x, l, r + 1) {
			int pos = -1;
			REP(i, n) {
				if (x % a[i] == 0) {
					pos = i;
					break;
				}
			}
			
			if (pos != -1) {
				pos++;
				if (pos & 1) ans++;
			}
			else {
				if (!(n & 1)) ans++;
			}
		}
		
		if (debug) printf("@ ");
		cout << ans << endl;
	}
	return 0;
}

// C
