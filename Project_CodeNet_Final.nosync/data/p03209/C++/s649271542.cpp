#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int max_n = 50;
ll a[max_n+1], p[max_n+1];

ll rec(ll n, ll x){
	if(n == 0) return 1;
	if(x == 1) return 0;
	if(1 < x && x < a[n-1] + 2) return rec(n-1, x-1);
	if(x == a[n-1] + 2) return p[n-1] + 1;
	if(a[n-1] + 2 < x && x < a[n]) {
		return p[n-1] + 1 + rec(n-1, x - a[n-1] - 2);
	}
	return p[n];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, x;
	cin >> n >> x;

	a[0] = 1;
	p[0] = 1;

	rep(i, n){
		a[i+1] = 2 * a[i] + 3;
		p[i+1] = 2 * p[i] + 1;
	}

	cout << rec(n, x) << endl;
}
