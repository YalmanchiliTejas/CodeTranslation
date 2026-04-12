#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	long long K;
	while(~scanf("%lld", &K)) {
		const int M = 8;
		const int X = 600;
		vector<vector<ll>> dp(X + 1, vector<ll>(M));
		rer(i, 0, X)
			dp[i][0] = 1;
		rep(i, X) {
			rep(j, M - 1)
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
		}
		vector<int> c(X + 1);
		for(int i = X; i >= 1; -- i) {
			c[i] = (int)(K / dp[i][M - 1]);
			K %= dp[i][M - 1];
		}
		string ans;
		rer(i, 1, X) {
			ans += "FESTIVA";
			rep(j, c[i])
				ans += 'L';
		}
		puts(ans.c_str());
	}
	return 0;
}
