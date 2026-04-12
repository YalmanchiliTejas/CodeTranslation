#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;
const ll mod=1e9+7;

int main(){
    ll n,all=0,ans=0;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        all+=a[i];
    }
    rep(i,n-1){
        all-=a[i];
        
        ans+=(a[i]%mod)*(all%mod);
        ans%=mod;
    }
    cout<<ans;
}