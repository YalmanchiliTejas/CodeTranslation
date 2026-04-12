#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int m, y, p, c, n;
ll f;
double r;

int main() {
	cin >> m;
	rep(t,m) {
		cin >> f >> y >> n;

		ll ans = 0;
		rep(i,n) {
			cin >> p >> r >> c;
			ll b = f;

			if(p == 0) {
				ll a = 0;
				rep(k,y) {
					a += (ll)(b * r);
					b -= c;
				}
				b = a + b;
			} else {
				rep(k,y) {
					b = (ll)(b * (1.0 + r) - c);
				}
			}

			if(b > ans) {
				ans = b;
			}
		}
		printf("%lld\n", ans);
	}
}