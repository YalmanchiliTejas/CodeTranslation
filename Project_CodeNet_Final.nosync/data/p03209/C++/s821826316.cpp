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

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int inf = 1e9 + 10;

int N, X;
bool done[55];
int len[55], dp[55];

int f(int n, int x)
{
	if (x == 0) return 0;
	if (x >= len[n]) return dp[n];

	int ans = 0;

	if (x - 1 >= len[n - 1]) {
		ans += dp[n - 1];
		x -= 1;
		x -= len[n - 1];
		if (x >= 1) {
			ans += 1;
			ans += f(n - 1, x - 1);
		}
	} else {
		ans += f(n - 1, x - 1);
	}

	return ans;
}

signed main()
{
	int N = 5; cin >> N;

	len[1] = 1;
	dp[1] = 1;

	rep1(i, N) {
		len[i + 1] = 3 + 2 * len[i];
		dp[i + 1] = 1 + 2 * dp[i];
	}

	int X; cin >> X;
	
	cout << f(N+1, X) << endl;
}

