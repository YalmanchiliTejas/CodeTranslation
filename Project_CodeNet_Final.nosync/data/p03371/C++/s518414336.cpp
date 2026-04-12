#include <cmath>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <numeric>

#define FOR(i,a,b) for(i=(a);i<(b);++i) 
#define REP(i,n) for(i=0;i<(n);++i)
#define ll long long
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807

using namespace std;

long long GCD(long long a, long long b) {
	if (a < b)
		swap(a, b);
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main() {
	int A,B,C,X,Y,i;
	ll ans = LL_MAX,sum;
	cin >> A >> B >> C >> X >> Y;
	REP(i, max(X, Y)+1) {
		sum = C * 2 * i + A * max(0,(X - i)) + B * max(0,(Y - i));
		ans = min((ll)sum, ans);
	}
	cout << ans << endl;
}