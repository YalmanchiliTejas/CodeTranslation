#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 200005;
//////////////////////////////

Int n, s;
Int a[3300];
Int dp[3300];

void solve()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	Int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = s - a[i]; j >= 0; j--) {
			if (j == 0) dp[a[i]] = (dp[a[i]] + (i + 1)) % 998244353;
			else dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % 998244353;
		}
		ans += dp[s];
	}

	cout << ans % 998244353 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
