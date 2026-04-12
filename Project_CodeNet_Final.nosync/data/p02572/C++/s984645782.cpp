#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using P =pair<int,int>;

const ll mod=1000000007;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=(a[i]%mod);
        sum%=mod;
    }

    ll ans=0;
    rep(i,n-1){
        sum-=(a[i]%mod);
        if(sum<0)sum+=mod;
        ans+=(((a[i]%mod)*sum)%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}