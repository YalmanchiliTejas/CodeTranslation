#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    vector<pair<ll,ll>> a;
    multiset<ll> b,r;
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        ll xi,yi;
        scanf("%lld%lld",&xi,&yi);
        if(xi>yi)
            swap(xi,yi);
        a.push_back({xi,yi});
        b.insert(xi);
        r.insert(yi);
    }
    sort(a.begin(),a.end());
    ll r2 = a[n+n-1].first,b1 = a[0].first,r1,b2;
    auto solve = [&](){
        return (*r.rbegin()-*r.begin())*(*b.rbegin()-*b.begin());
    };
    ll ans = solve();
    for(int i = 0; i<n; i++){
        b.erase(b.find(a[i].first));
        r.insert(a[i].first);
        r.erase(r.find(a[i].second));
        b.insert(a[i].second);
        ans = min(ans,solve());
    }
    printf("%lld\n",ans);
    return 0;
}