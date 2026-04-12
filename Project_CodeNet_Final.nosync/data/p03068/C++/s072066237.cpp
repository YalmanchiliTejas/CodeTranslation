// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define F first
#define S second
#define sz(x) (int)x.size() - 1
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define fo(i, n)   for (int i = 1; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int >
#define E cout << '\n'

const int mod = 1e9 + 7;
const int N = 3e5 + 5;


inline void solve() {
 int n, k;string s;
 cin >> n >> s >> k;
 char ch = s[k-1];
 for(auto &i : s)
    if(i != ch)
    i = '*';
    cout << s;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; while(t--)
                solve();
    return 0;
}
