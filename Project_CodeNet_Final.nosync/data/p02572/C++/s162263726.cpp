#include<bits/stdc++.h>

using namespace std;
mt19937_64 rng(58);
const int64_t MOD = 1e9 + 7;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) { bool first = true; string res = ""; for (const auto &x : v) { if (!first) res += ", "; first = false; res += to_string(x); } return "{" + res + "}"; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int64_t> a(n); for (auto &ai : a) cin >> ai;
    vector<int64_t> s(n);
    s[n-1] = 0;
    for (int i = n-2; i >= 0; i--) s[i] = (s[i + 1] + a[i + 1]) % MOD;
    // debug(a);
    // debug(s);
    int64_t ans = 0;
    for (int i = 0; i<n; i++)
        ans = (ans + (a[i] * s[i]) % MOD) % MOD;
    cout << ans << endl;
}