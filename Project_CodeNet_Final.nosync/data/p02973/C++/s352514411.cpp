#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int INF = 1e9 + 10;

int N;
int A[100010];
int dp[100010];

signed main()
{
	cin >> N;

	rep1(i, N) cin >> A[i], A[i] *= -1;

	rep(i, N + 5) dp[i] = INF;

	rep1(i, N) {
		int idx = upper_bound(dp, dp + N + 1, A[i]) - dp;
		dp[idx] = A[i];
	}

	int ans = lower_bound(dp, dp + N + 3, INF) - dp;

	cout << ans << endl;
}

