#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	ll a[n];
	rep(i,n) cin >> a[i];

	ll ans = 0;
	bool upd = true;
	while(upd){
		upd = false;
		rep(i,n){
			if(a[i] >= n){
				upd = true;
				ll b = a[i] / n;
				ans += b;
				rep(j,n){
					if(j == i) a[j] %= n;
					else a[j] += b;
				}
			}
		}
	}

	cout << ans << endl;
}