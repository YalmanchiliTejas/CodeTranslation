#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = (ll)1e14;
const ll N = (ll)1e3+77;
const ll mod = (ll)1e9+7;

int main() {
    fast;
    string s;
    cin >> s;
    forn(i, sz(s) - 1) {
        if (s[i] == 'A' and s[i+1] == 'C') return cout << "Yes\n", 0;
    }
    cout << "No\n";
    return 0;
}