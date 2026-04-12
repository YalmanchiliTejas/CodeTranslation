#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
typedef long long  ll;

#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
ll MOD = 1000000007;

int main() {
	ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	ll a = X * A + Y * B;
	ll b = 2 * C * min(X, Y) + ((X - Y) > 0 ? A * (X - Y) : B * (Y - X));
	ll c = 2 * C * ((X - Y) > 0 ? X : Y);

	cout << min(a, min(b, c)) << endl;
	return 0;
}