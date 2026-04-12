#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ll n; cin >> n;
    ll x, m; cin >> x >> m;
    vector<int> a;
    set<int> st;
    int loopNum = -1;
    rep(i, n) {
        if (i>0) {
            x *= x;
            x %= m;
        }
        if (st.count(x)) {
            loopNum = x;
            break;
        }
        a.push_back(x);
        st.insert(x);
    }
    if (loopNum == -1) {
        cout << accumulate(all(a), 0ll) << endl;
    } else {
        int start = find(a.begin(), a.end(), loopNum) - a.begin();
        int end = sz(a)-1;
        // debug(start, end);
        int loopLength = end - start + 1;
        ll beforeLoop = accumulate(a.begin(), a.begin()+start, 0ll);
        ll loopTotal = accumulate(a.begin()+start, a.end(), 0ll);
        ll loopCount = (n-start) / loopLength;
        ll restCount = n - start - (ll)loopLength*loopCount;
        ll loopRemain = accumulate(a.begin()+start, a.begin()+start+restCount, 0ll);
        ll ans = beforeLoop + loopTotal*loopCount + loopRemain;
        // debug(a);
        // debug(*(a.begin()+start));
        // debug(start, loopLength, loopCount, restCount);
        // debug(beforeLoop, loopTotal, loopCount, restCount, loopTotal*loopCount, loopRemain);
        // debug(accumulate(all(a), 0ll));
        cout << ans << endl;
    }
}