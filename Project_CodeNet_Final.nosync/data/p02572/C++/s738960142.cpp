#include<bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using namespace std;
constexpr int inf = 1<<30;
constexpr int mo = 1e9+7;
constexpr ll infl = 1ll<<60;


int main(){
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    vector<ll> s(n);
    for(auto & b : a) cin>>b,sum+=b,sum%=mo;
    s[0] = a[0];
    for(int i=1;i<n;++i){
        s[i] = s[i-1] + a[i];
        s[i] %=mo;
    }
    ll ret =0ll;
    for(int i=0;i<n;++i){
        ll tmp = sum - s[i];
        if(tmp < 0)tmp +=mo;
        tmp %= mo;
        ret += (tmp * a[i])%mo;
        ret %= mo;
    }
    cout  << ret << endl;
    return 0;
    
}
