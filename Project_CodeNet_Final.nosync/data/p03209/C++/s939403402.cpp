#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> all(1, 1);
    for(ll i = 0; i < 50; ++i)
        all.push_back(all.back() * 2 + 3);

    vector<ll> pat(1, 1);
    for(ll i = 0; i < 50; ++i)
        pat.push_back(pat.back() * 2 + 1);

    // [0,index)
    function<ll(ll,ll)> calc = [&](ll level, ll index){
        if(level == 0)
            return index;

        if(!index)
            return 0LL;
        --index;
        ll ans = 0;
        if(index < all[level - 1]){
            return calc(level - 1, index);
        }else{
            ans += pat[level - 1];
            index -= all[level - 1];
        }
        if(index < 2)
            return ans + index;
        --index;
        ++ans;
        return ans + calc(level - 1, min(all[level - 1], index));
    };

    cout << calc(n, x) << endl;
}
