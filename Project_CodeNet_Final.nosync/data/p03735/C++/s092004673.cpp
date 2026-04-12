#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e18;
vector<pair<ll,ll>> a;
multiset<ll>r,b;
int n;
ll ans;
int main(){
    cin >> n;
    a.resize(n);
    ans = maxn;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second)
            swap(a[i].first,a[i].second);
    }
    sort(a.begin(), a.end());
    for(auto p:a){
        r.insert(p.first);
        b.insert(p.second);
    }
    ans = min((*r.rbegin() - *r.begin()) * (*b.rbegin() - *b.begin()), ans);
    for(auto p:a){
        r.erase(r.find(p.first));
        b.erase(b.find(p.second));
        r.insert(p.second);
        b.insert(p.first);
        ans = min((*r.rbegin() - *r.begin()) * (*b.rbegin() - *b.begin()), ans);     
    }
    printf("%lld\n", ans);
    return 0;
}