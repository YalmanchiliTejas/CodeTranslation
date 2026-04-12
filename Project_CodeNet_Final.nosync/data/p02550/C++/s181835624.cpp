#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<vector<vector<int>>> v3int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef vector<vector<vector<ll>>> v3ll;
typedef list<int> liint;
typedef pair<int, int> pint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<ll, int>> vpll_int;
typedef vector<pair<int, ll>> vpint_ll;
typedef set<pair<int, int>> spint;
typedef set<pair<ll, int>> spll;
typedef unordered_map<int, unordered_set<int>> Graph;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }


ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, X, M;

    cin >> N >> X >> M;

    //ll t = 1;
    set<ll> apear;
    vll ordered;
    ll modX = X;
    ll twice = -1;
    rep(i, N) {
        if (apear.count(modX) > 0) {
            twice = modX;
            break;
        }
        apear.insert(modX);
        ordered.push_back(modX);
        modX *= modX;
        modX %= M;
       // ans += modX;
        //cout << modX << endl;
        //t *= 2;
    }
    ll ans = 0;
    ll t = N;
    vll peri;
    rep(i, ordered.size()) {
        if (ordered[i] == twice) {
            REP(j, i, ordered.size()) {
                peri.push_back(ordered[j]);
            }
            break;
        }
        ans += ordered[i];
        t--;
    }
    if (twice != -1) {
        ll mul = t / peri.size();
        ll add = t % peri.size();
        rep(i, peri.size()) {
            ans += mul * peri[i];
            if (i < add) {
                ans += peri[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}