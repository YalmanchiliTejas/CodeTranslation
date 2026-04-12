//In the name of ALLAH
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
const bool DEBUG = false;
#define cerr if(DEBUG)cerr
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const long long maxn = 2e5 + 5;
const long long INF = 1e18 + 1;
const long long M = 1e9 + 7;
const int lg = 21;

ll n, k, ans;

ll f(ll b){
	ll now = k, ans = 0;
	while(now <= n){
		ll nxt = now + (b - 1 - k);		
		nxt = min(nxt, n);
		ans += (nxt - now + 1);
		now = nxt + 1;
		now += k;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	if(k == 0)
		return cout << (ll)n * n << endl, 0;
	for(int b = k + 1; b <= n; b++)
		ans += f(b);
	cout << ans << endl;
	return 0;
}
