#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100005];
ll lis(ll n) {
    ll INF = 1e9;
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (ll i = 0; i < n; i++) {
        ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]*=(-1);
    }
    cout<<lis(n);
}