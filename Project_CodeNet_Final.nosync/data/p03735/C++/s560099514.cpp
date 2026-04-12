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
#include <time.h>
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
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
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
double eps = 1e-12;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[N], y[N];
    REP(i, 0, N) {
        cin >> x[i] >> y[i];
    }
    ll maxsort[N], minsort[N];
    REP(i, 0, N) {
        if (x[i] >= y[i]) {
            maxsort[i] = x[i];
            minsort[i] = y[i];
        } else {
            maxsort[i] = y[i];
            minsort[i] = x[i];
        }
    }
    sort(maxsort, maxsort + N);
    sort(minsort, minsort + N);
    ll ans = (maxsort[N - 1] - maxsort[0]) * (minsort[N - 1] - minsort[0]);
    ll usedmark[N];
    fill(usedmark, usedmark + N, 0);
    ll tmp = 0;
    plglg balls[2 * N];
    REP(i, 0, N) {
        balls[i * 2] = plglg(x[i], i);
        balls[i * 2 + 1] = plglg(y[i], i);
    }
    sort(balls, balls + 2 * N);
    ll minnum = 0;
    ll ite = -1;
    while(tmp < N) {
        ite++;
        plglg ball = balls[ite];
        ll ind = ball.second;
        if (usedmark[ind] == 0) {
            tmp++;
        }
        usedmark[ind]++;
    }
    ll widedis = balls[2 * N - 1].first - balls[0].first;
    ll mindis = balls[ite].first - balls[minnum].first;
    while(1) {
        while(tmp == N) {
            mindis = min(mindis, balls[ite].first - balls[minnum].first);
            plglg popball = balls[minnum];
            ll ind = popball.second;
            usedmark[ind]--;
            if (usedmark[ind] == 0) {
                tmp--;
            }
            minnum++;
        }
        while(tmp < N && ite < 2 * N - 1) {
            ite++;
            plglg ball = balls[ite];
            ll ind = ball.second;
            if (usedmark[ind] == 0) {
                tmp++;
            }
            usedmark[ind]++;
        }
        if (ite == 2 * N - 1) {
            break;
        }
    }
    ll ansb = widedis * mindis;
    cout << min(ans, ansb) << endl;
}
