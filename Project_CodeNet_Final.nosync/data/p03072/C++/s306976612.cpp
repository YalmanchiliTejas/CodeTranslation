#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n-1;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 999999999
typedef pair<ll, ll> LP;

ll max(ll a, ll b){
	if (a>b) return a;
	else return b;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> h(n);
	REP(i, n){cin >> h[i];}
	ll ans = 1;
	if (n==1){cout << ans << endl; return 0;}
	ll m = h[0];
	FOR(i, 1, n){
		if (h[i]>=m){
			ans++;
			m = h[i];
		}
	}
	cout << ans << endl;
}