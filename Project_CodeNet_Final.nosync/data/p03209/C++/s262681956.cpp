#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
#define REP(i, x, y) for(ll i = x; i < y; i++)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

ll nums[60];
ll p[60];

ll solve(int lev, ll num) {
    if (lev == 0) {
        if (num == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (num == 1) {
            return 0;
        } else if (num <= nums[lev - 1] + 1) {
            return solve(lev - 1, num - 1);
        } else if (num == nums[lev - 1] + 2) {
            return p[lev - 1] + 1;
        } else if (num <= nums[lev - 1] * 2 + 2) {
            return solve(lev - 1, num - (nums[lev - 1] + 2)) + p[lev - 1] + 1;
        } else {
            return p[lev - 1] * 2 + 1;
        }
    }
}

int main() {
    ll N, X;
    cin >> N >> X;
    nums[0] = 1;
    p[0] = 1;
    REP(i, 1, 55) {
        nums[i] = nums[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    ll ans = solve(N, X);
    cout << ans << endl;
}
