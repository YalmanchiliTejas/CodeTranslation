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
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n, x, m;
map<llint, llint> mp;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> m;
	
	mp[x] = 1, a[1] = x;
	llint pos, per;
	for(int i = 2; ; i++){
		x *= x, x %= m;
		a[i] = x;
		if(mp.count(x)){
			pos = mp[x];
			per = i - mp[x];
			break;
		}
		mp[x] = i;
	}
	
	//cout << pos << " " << per << endl;
	
	llint ans = 0;
	for(int i = 1; i <= min(pos-1, n); i++) ans += a[i];
	
	
	n -= (pos-1);
	if(n <= 0){
		cout << ans << endl;
		return 0;
	}
	
	llint sum = 0;
	for(int i = 0; i < per; i++) sum += a[pos+i];
	
	ans += n/per*sum;
	n %= per;
	for(int i = 0; i < n; i++) ans += a[pos+i];
	cout << ans << endl;
	
	return 0;
}