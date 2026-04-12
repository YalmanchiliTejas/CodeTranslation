#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <numeric>
#include <complex>

#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define repr(i, a, b) for(int i=int(a); i>=int(b); i--)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
typedef long long int ll;
#define iceil(x,y) (x+y-1)/y

using namespace std;
typedef pair<int, int> P;

int main() {
	FAST;

	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;

	int f1=0,f2=0,f3=0;
	if (c < a+b) f1=1;
	if (c<a) f2=1;
	if (c<b) f3=1;
	int sxy = min(x,y);
	int sum = 0;

	if (f1) {
		x-=sxy;
		y-=sxy;
		sum += c*sxy;
		if (x>y) {
			if (f2) sum += c*x;
			else sum += a*x;
		}
		else {
			if (f3) sum += c*y;
			else sum += b*y;
		}
	}
	else {
		sum+=a*x+b*y;
	}

	cout << sum << "\n";

	return 0;
}