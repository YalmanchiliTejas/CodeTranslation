#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

const double eps = 1e-7;
const int MOD = 1000000007;
const int MOD_MAX = 200000;

using ll = long long;
using vi = vector<int>; using vi2 = vector<vi>; using vi3 = vector<vi2>;
using vll = vector<ll>; using vll2 = vector<vll>; using vll3 = vector<vll2>;
using vd = vector<double>; using vd2 = vector<vd>; using vd3 = vector<vd2>;
using pi = pair<int, int>; using pll = pair<ll, ll>;
using vpi = vector<pi>; using vpll = vector<pll>;

#define loopi(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define loop(i, n) for (int i = 0; i < (int)n; i++)
#define loopeq(i, n) for (int i = 0; i <= (int)n; i++)
#define loopll(i, n) for (ll i = 0; i < (ll)n; i++)
#define looplleq(i, n) for (ll i = 0; i <= (ll)n; i++)
#define rloopi(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define rloop(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define rloopeq(i, n) for (int i = (int)n - 1; i >= 1; i--)
#define rloopll(i, n) for (int i = (ll)n - 1; i >= 0; i--)
#define rlooplleq(i, n) for (int i = (ll)n - 1; i >= 1; i--)
#define all(a) (a).begin(), (a).end()

int main() {
	string s; cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else cout << "Yes" << endl;
}
