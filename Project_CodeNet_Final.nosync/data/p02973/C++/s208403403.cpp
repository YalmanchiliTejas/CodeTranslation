#ifdef loc
    #include "codes/loc_debug.h"
#else
    #include <bits/stdc++.h>
    #define pr(...)
    #define pra(a,n)
    #define praa(a,n,m)
    #define prl()
#endif
using namespace std;

typedef long long ll;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sz(a) int(a.size())
const int N = 200005;

int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    multiset<int> b;
    int res = 0;
    rep(i, 1, n + 1) {
        auto it = b.lower_bound(a[i]);
        if(it == b.begin()) {
            res++;
        } else {
            it--;
            b.erase(it);
        }
        b.insert(a[i]);
    }
    cout << res << endl;
}