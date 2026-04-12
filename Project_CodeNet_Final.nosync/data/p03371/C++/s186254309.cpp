#include <iostream>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a * b / gcd(a, b); }

#define in(x) cin >> x
#define out(x) cout << x
#define outn(x) cout << x << '\n'
#define outs(x) cout << x << ' '
#define rep(i,s,e) for(long i=s;i<e;i++)
#define repeq(i,s,e) for(long i=s;i<=e;i++)


int main() {
	ll a, b, c, x, y;
	ll p,ans;
	in(a);
	in(b);
	in(c);
	in(x);
	in(y);

	if (2*c < a+b ) {
		if (x < y) {
			ans = c * x * 2;
			if (2 * c < b) {
				ans += c * (y - x) * 2;
			}
			else {
				ans += b * (y - x);
			}
		}
		else {
			ans = c * y * 2;
			if (2 * c < a) {
				ans += c * (x - y) * 2;
			}
			else {
				ans += a * (x - y);
			}
		}
	}
	else {
		ans = a * x + b * y;
	}

	outn(ans);
	return 0;

	}
	