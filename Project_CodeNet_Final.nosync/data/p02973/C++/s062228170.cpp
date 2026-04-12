#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"

using namespace std;

typedef long int li;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pt;

#define fi first
#define se second
#define dump(x) cout << #x << " = " << x << endl
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

li n, a[100007], res;
multiset <int, greater <int>> mt;


int main () {
    fastIO;
    cin >> n;
    for(li i = 0; i < n; i ++) cin >> a[i];
    res=1;
    mt.insert(a[0]);
    for(li i = 1; i < n; i ++) {
        auto it = mt.upper_bound(a[i]);
        if(it==mt.end()) {
            res++;
            mt.insert(a[i]);
        } else {
            mt.erase(it);
            mt.insert(a[i]);
        }
    }
    cout << res;
}
