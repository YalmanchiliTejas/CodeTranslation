// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!
 
#pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 3
#endif
 
#define cin_exception cin.exceptions(cin.failbit);
#define cout_precision cout.setf(ios::fixed); cout.precision(15);
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = int_fast64_t; using ld = long double;

// -----------------------------------------------------------------------------

void solve() {
    string s; cin >> s;
    if (s == "BBB" || s == "AAA") {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
}

int main() {
    fast_io; cin_exception;
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}