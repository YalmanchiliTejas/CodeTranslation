#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    bool visited[m];
    vector<ll> mods(m);
    for(int i = 0; i < m; i++) {
        mods[i] = ((ll)i*i)%m;
        visited[i] = false;
    }
    visited[x] = true;
    ll len = 1, cnum = x, start = -1;
    vector<ll> vals = {x};
    for(int i = 2; i <= n; i++) {
        cnum = ((ll)cnum*cnum)%m;
        if(!visited[cnum]) {
            visited[cnum] = true;
            vals.push_back(cnum);
            len++;
        }
        else {
            start = cnum;
            break;
        }
    }
    ll ans = 0;
    for(int i = 0; i < vals.size(); i++) {
        if(vals[i] == start) {
            len -= i;
            start = i;
            break;
        }
        else {
            ans += vals[i];
            n--;
        }
    }
    if(start != -1) {
        for(int i = start; i < vals.size(); i++) {
            ans += (ll)vals[i]*(n/len);
        }
        n %= len;
        for(int i = start; i < vals.size(), n > 0; i++, n--) {
            ans += vals[i];
        }
    }
    cout << ans;
    return 0;
}