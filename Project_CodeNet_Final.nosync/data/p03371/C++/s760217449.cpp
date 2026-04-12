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
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll t1 = ((X > Y) ? X : Y) * C * 2;
	ll t2 = X * A + Y * B;;
	ll t3 = ((X > Y) ? Y : X) * C * 2 + ((X > Y) ? (X - Y) * A : (Y - X) * B);

	cout << min(min(t1, t2), t3) << endl;

	return 0;
}