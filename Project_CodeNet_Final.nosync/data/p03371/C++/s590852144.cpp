#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define reprrev(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define reprev(i, n) reprrev(i, 0, n)
#define mp(a, b) make_pair(a, b)
#define all(vec) (vec).begin(), (vec).end()
#define yn(formula) (formula) ? (cout << "Yes" << endl) : (cout << "No" << endl)
#define YN(formula) (formula) ? (cout << "YES" << endl) : (cout << "NO" << endl)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vp;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vp> vvp;
typedef vector<vpl> vvpl;

constexpr double PI = 3.14159265358979323846;
constexpr ll INF = 1 << 29;
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-7;
constexpr int dy[4] = { 0, 1, 0, -1 };
constexpr int dx[4] = { 1, 0, -1, 0 };

struct edge { ll to; ll cost; };

/*<ここから>***********************************************************/


int main()
{
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll ans = 5000 * 100000 * 2 + 1;
	for (ll ab = 0; ab <= max(X, Y) * 2; ab += 2) {

		ll x = X - ab / 2, y = Y - ab / 2;
		ll cost = ll(ab * C);
		if (x > 0) cost += ll(x * A);
		if (y > 0) cost += ll(y * B);
		if (cost < ans)	ans = cost;
	}

	cout << ans << endl;


	return 0;
}