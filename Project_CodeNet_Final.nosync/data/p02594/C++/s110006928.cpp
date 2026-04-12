
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/**
 * @author dwij
 */

#include <bits/stdc++.h>

#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>

using namespace std;

//******* Debugging Class Template *******/
#define sim template <class c
#define ris return *this
#define dor > deb& operator<<
#define eni(x) \
    sim > typename enable_if<sizeof dud<c>(0) x 1, deb&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct deb {
#ifdef LOCAL
    ~deb() { cerr << endl; }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&) { ris; }
#endif
}
;
#define log(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// End of weird debugging stuff.

typedef long long ll;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<ll, ll>

#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define endl "\n"

void solution() {
    // deb() << log();
    int n;
    cin >> n;
    if (n >= 30)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    // cin.ignore(); //must be there when using getline(cin, s)
    for (int tt = 1; tt <= T; tt++) {
        // cout << "Case #" << tt << ": ";
        solution();
    }

    return 0;
}
