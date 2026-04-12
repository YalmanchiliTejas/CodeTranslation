#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);i++)
#define urep(i,a,n) for(ll i = (a);i>=(n);i--)
#define all(x) (x).begin(),(x).end()
#define INF 1e9
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll N, M, Q;
ll A[100001];
ll B[100001];
ll ans;
string S;
ll K;
map<ll, ll> m;
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
int main() {
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ans = A * X + B * Y;
	if (X <= Y)
		ans = min(ans, C * 2 * X + B * (Y - X));
	else
		ans = min(ans, C * 2 * Y + A * (X - Y));
	ans = min(ans, C * 2 * max(X, Y));
	cout << ans << endl;
	cin >> ans;
	return 0;
}