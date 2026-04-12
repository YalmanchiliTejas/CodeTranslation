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
#define PER(i, x, y) for(ll i = x; i > y; i--)
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

int main() {
    ll N;
    cin >> N;
    ll a[N];
    REP(i, 0, N) {
        cin >> a[i];
    }
    sort(a, a + N);
    reverse(a, a + N);
    ll ans = 0;
    while (1) {
        bool ok = true;
        REP(i, 0, N) {
            if (a[i] >= N) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        REP(i, 0, N) {
            ll num = a[i] / N;
            ans += num;
            REP(j, 0, N) {
                if (j == i) {
                    a[j] -= num * N;
                } else {
                    a[j] += num;
                }
            }
        }
    }
    cout << ans << endl;
}
