#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <numeric>
#include <complex>
#include <tuple>

#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define repr(i, a, b) for(int i=int(a); i>=int(b); i--)
#define reps(i,n) for(int i=1;i<=int(n);++i)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define iceil(x,y) (x+y-1)/y
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII> PP;

ll n,x;
ll pat[52];
ll size[52];

ll ans=0;

ll solve(ll n, ll x) {
	if (x==0) return 0;
	if (n==0) return 1;

	if (x <= 1 + size[n-1]) {
		return solve(n-1, x-1);
	}
	else {
		return pat[n-1]+1+solve(n-1,x-2-size[n-1]);
	}
}

int main()
{
	FAST;

	cin >> n >> x;
	pat[0] = 1;
	size[0] = 1;
	reps(i,50) {
		pat[i] = 2*pat[i-1] + 1;
		size[i] = 2*size[i-1] + 3;
	}

	cout << solve(n,x) << "\n";

	return 0;
}