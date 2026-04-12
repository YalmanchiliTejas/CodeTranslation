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

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
llint p[100005], pinv[100005];
llint a[100005], b[100005];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) p[i] = pinv[i] = i;
	for(int i = 1; i <= Q; i++) cin >> a[i] >> b[i];
	S.insert(1);
	
	llint u, v;
	for(int i = 0; i <= Q; i++){
		swap(p[a[i]], p[b[i]]);
		swap(pinv[p[a[i]]], pinv[p[b[i]]]);
		llint x = pinv[1];
		if(x > 1) S.insert(p[x-1]);
		if(x < n) S.insert(p[x+1]);
	}
	cout << S.size() << endl;
	
	return 0;
}