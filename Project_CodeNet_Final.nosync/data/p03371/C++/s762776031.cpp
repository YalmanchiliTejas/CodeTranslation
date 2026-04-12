#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)

int main() {
	ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	ll v1 = X * A + Y * B;
	ll v2 = min(X, Y) * 2 * C + abs(X - Y) * ((X >= Y) ? A : B);
	ll v3 = max(X, Y) * 2 * C;
	cout << min(v3, min(v1, v2)) << endl;
	return 0;
}