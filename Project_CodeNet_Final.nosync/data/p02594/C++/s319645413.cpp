#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a); i<(n); i++)
#define per(i, a, n) for (int i=(a); i>(n); i--)
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
using namespace std;

void solve() {
	ll x; cin >> x;
	if (x >= 30) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main(int argc, char * argv[]) 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef DEBUG
	freopen("C:/Users/Fish_Brother/Desktop/in", "r", stdin);
	//freopen("C:/Users/Fish_Brother/Desktop/out", "w", stdout);
#endif

	//int t; cin >> t; while(t--)
	solve();

    return 0;
}