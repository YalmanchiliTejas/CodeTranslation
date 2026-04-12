#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i], ans %= mod;
	}
	ans *= ans, ans %= mod;
	
	for(int i = 1; i<= n; i++) ans += mod - a[i]*a[i]%mod, ans %= mod;
	ans *= (mod+1)/2, ans %= mod;
	cout << ans << endl;
	
	return 0;
}