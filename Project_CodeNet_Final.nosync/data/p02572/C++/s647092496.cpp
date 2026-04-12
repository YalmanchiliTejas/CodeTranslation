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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];
    vll S(N + 1);
    rep(i, N) {
        S[i + 1] = A[i] + S[i];
    }

    ll ans = 0;
    ll p = 1000000007;
    rep(i, N) {
        ans = ans + (((A[i] % p) * ((S[N] - S[i + 1]) % p)) % p);
        ans %= p;
    }
    cout << ans << endl;
    return 0;
}