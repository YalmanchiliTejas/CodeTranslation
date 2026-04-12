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
#define PI acos(-1)
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int modpow(int x, int n, int m) {
	x %= m;
	int res = 1;
	while(n > 0) {
		if(n & 1)
			res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifndef ONLINE_JUDGE
		// freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	if(n == m) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}