#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<ll> ans(n,1e9+7);
    for(i = n-1;i >= 0;--i){
        auto it = upper_bound(all(ans), a.at(i));
        *it = a.at(i);
    }
    auto it = lower_bound(all(ans), 1e9 + 7) - ans.begin();
    cout << it << endl;
    return 0;
}