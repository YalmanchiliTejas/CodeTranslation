#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 998244353;
const int N = 1e6 + 10;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, x, m;
	cin >> n >> x >> m;
	int ans = x;
	bool vis[m] = {0};
	int cur = x * x % m;
	vi v;
	while(!vis[cur]) {
		v.pb(cur);
		vis[cur] = 1;
		cur = cur * cur % m;
	}
	if(v.back() == 0) {
		for(int i = 0; i < min(n - 1, (int)v.size()); i++) {
			ans += v[i];
		}
	}
	else {
		int j = 0;
		for(int i = 0; i < (int)v.size(); i++) {
			if(v[i] == cur) {
				j = i;
				break;
			}
		}
		int cnt = 0;
		for(int i = 0; i < min(n - 1, j); i++) {
			ans += v[i];
			cnt++;
		}
		n -= (cnt + 1);
		int tot = 0;
		for(int i = j; i < v.size(); i++) {
			tot += v[i];
		}
		int sz = (int)v.size() - j;
		ans += (n / sz) * tot;
		for(int i = j; i < j + (n % sz); i++) {
			ans += v[i];
		}
	}
	cout << ans;

	return 0;
}