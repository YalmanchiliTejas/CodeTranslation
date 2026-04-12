
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef long long ll;
const ll LL_MAX (1LL<<60);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i,0,n) cin >> h[i];

    ll _max(-LL_MAX), cnt(0);

    rep(i,0,n)
        if (h[i]>=_max) cnt++, _max = h[i];

    cout << cnt << endl;

    return 0;
}
