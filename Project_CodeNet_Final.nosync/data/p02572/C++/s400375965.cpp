#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0;
    ll mod=1000000007;
    rep(i,n){
        ll c;
        cin >> c;
        a[i]=c;
        sum+=c;
    }
    vector<ll> b(n);
    rep(i,n){
        sum-=a[i];
        b[i]=sum;
        b[i]=b[i]%mod;
    }
    ll ans=0;
    rep(i,n){
        ans+=((a[i]*b[i])%mod);
        ans=ans%mod;
    }
    cout << ans << "\n";
    return 0;
}   