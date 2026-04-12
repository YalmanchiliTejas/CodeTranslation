#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <time.h>
#include <vector>

using namespace std;
typedef long long ll;
template <class T = ll>
T in() {
    T x;
    cin >> x;
    return (x);
}
template <class T>
void print(T x) {
    cout << x << "\n";
}
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define reps(x, c) for (auto x : c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a)
#define mp(a, b) make_pair((a), (b))
#define pl pair<ll, ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cerr << #x "=" << (x) << "\n"
#define dbgv(x) \
    cerr << #x << "\n"; \
    reps(y, x) { cerr << y << " "; } \
    cerr << "\n"

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll k;
    cin >> k;

    rep(i, n) {
        if (s[i] != s[k - 1]) {
            s[i] = '*';
        }
    }
    cout << s << endl;
}