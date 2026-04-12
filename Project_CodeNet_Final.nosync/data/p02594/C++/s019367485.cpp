#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;      typedef vector<int> vi;
typedef vector<vl> vvl;     typedef vector<vi> vvi;
typedef pair<ll, ll> pll;   typedef pair<int, int> pii;
#define forn(i,n) for(int i=0;i<n;i++)
#define rforn(i,n) for(int i=n-1;i>=0;i--)
#define forne(i,n) for(int i=1;i<=n;i++)
#define forse(i,s,e) for(int i=s;i<e;i++)
#define rforse(i,s,e) for(int i=e-1;i>=s;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define MOD 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fill(a,x) memset(a,x,sizeof a);
#define trav(a,x) for(auto &a:x)
#define INF ll(1e18)
#ifdef SHUBHAM107
#include "../trace.h"
#else
#define trace(args...)
#endif

void solve() {
    int x;
    cin >> x;
    if (x >= 30)
        cout << "Yes";
    else
        cout << "No";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef SHUBHAM107
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
