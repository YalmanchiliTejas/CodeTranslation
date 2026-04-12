#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)




int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll mn1 = INF, mx1 = 0, mn2 = INF, mx2 = 0;
    REP(i, n){
        ll x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        mn1 = min(mn1, x);
        mx1 = max(mx1, x);
        mn2 = min(mn2, y);
        mx2 = max(mx2, y);
        v[i] = {x, y};
    }
    
    ll ans = (mx1 - mn1) * (mx2 - mn2);
    
    sort(v.begin(), v.end());
    
    ll mx3 = 0, mn3 = INF, mx4 = max(mx1, mx2), mn4 = min(mn1, mn2);
    ll t = INF;
    mx3 = v[n - 1].first;
    REP(i, n - 1){
        t = min(t, v[i].second);
        mx3 = max(mx3, v[i].second);
        mn3 = min(v[i + 1].first, t);
        ans = min(ans, (mx4 - mn4) * (mx3 - mn3));
    }
    cout << ans << endl;
}