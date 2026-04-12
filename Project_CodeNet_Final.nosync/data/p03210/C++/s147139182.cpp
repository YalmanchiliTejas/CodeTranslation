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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int x,y,z,t1,t2,t3;

int main()
{
	FAST;

	int x;
	cin >> x;
	if (x==3||x==5||x==7) cout <<"YES\n";
	else cout << "NO\n";

	return 0;
}