#include "bits/stdc++.h"
using namespace std;

#define mod 1e9 + 7
#define INF (int) 1e9 + 5

#define add emplace
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define len(x) ((int)(x).size())
#define exist(a, x) (a.find(x) != end(a))
#define log(x) cout << (x) << endl;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rrep(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define loop(i,a,b) for(int i=(int)(a);i<(int)(b);++i)

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vstr = vector<string>;


ll dp[3005][3005][2]={};
vll best2(vll& a, int n) {
	int i=0, j=0;
	int winsize = 1;

	while (winsize <= n) {
		i = 0, j = winsize - 1;

		while (j < n) {
			if (i == j) {
				dp[i][i][0]=a[i];
				dp[i][i][1]=0;
			}
			else {
				ll * fr = dp[i+1][j],
					* ba = dp[i][j-1];

				ll frnt = a[i] + fr[1],
					bck = a[j] + ba[1];

				if (frnt > bck)
					dp[i][j][0] = frnt, dp[i][j][1] = fr[0];
				else
					dp[i][j][0] = bck, dp[i][j][1] = ba[0];
			}
			++i, ++j;
		}
		++winsize;
	}

	return {dp[0][n-1][0], dp[0][n-1][1]};
}


int main() {
	int n; cin >> n;
	vll a(n);
	rep (i, n)
		cin>>a[i];
	vll s = best2(a, n);
	printf("%lld\n", s[0]-s[1]);
	return 0;
}
