#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
// const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (1) {
		int N,A,B,C,X; cin >> N >> A >> B >> C >> X;
		if (N+A+B+C+X==0) break;
		vector<int> Y(N);
		rep(i,N) cin >> Y[i];

		int now = 0;
		int ans = -1;
		if (X==Y[0]) {
			now++;
			if (now == N) ans = 0;
		}
		rep(i,10000) {
			X = (A*X+B)%C;
			if (now < N && Y[now]==X) {
				now++;
				if (now == N) ans = i+1;
			}
		}
		cout << ans << endl;

	}
}
