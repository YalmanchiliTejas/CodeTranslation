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
    sort(all(a));
    ll ans = 0;
    if(n%2){
        ll tm = 0;
        ll tp = 0;
        for(i = 0;i < (n-1)/2;++i){
            tm += 2*a.at(i);
        }
        for(i = (n-1)/2;i < n;++i){
            tp += 2*a.at(i);
        }
        tp -= a.at((n-1)/2);
        tp -= a.at((n+1)/2);
        ans = tp - tm;
        tp = 0; tm = 0;
        for(i = 0;i < (n+1)/2;++i){
            tm += 2*a.at(i);
        }
        for(i = (n+1)/2;i < n;++i){
            tp += 2*a.at(i);
        }
        tm -= a.at((n-1)/2);
        tm -= a.at((n-3)/2);
        ll tmp = tp - tm;
        ans = max(ans, tmp);
    }else{
        ll minus = 0;
        for(i = 0;i < n/2;++i){
            minus += 2*a.at(i);
        }
        minus -= a.at(n/2-1);
        ll plus = 0;
        for(i = n/2;i < n;++i){
            plus += 2*a.at(i);
        }
        plus -= a.at(n/2);
        ans = plus - minus;
    }
    cout << ans << endl;

    return 0;
}