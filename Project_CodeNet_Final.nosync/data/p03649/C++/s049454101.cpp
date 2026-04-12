#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll n,sum=0;
    cin>>n;
    vec A(n),B(n);
    rep(i,n) cin>>A[i],B[i]=A[i];
    rep(i,1000){
        if(*max_element(all(B))<n){
            cout<<i<<"\n";
            return 0;
        }
        *max_element(all(B))-=n+1;
        rep(j,n) B[j]++;
    }
    rep(i,n) sum+=A[i],A[i]%=n+1;
    ll ans=0;
    rep(i,n+1){
        ll a=0,z=1;
        rep(j,n){
            if((A[j]+i)%(n+1)==n) z=0;
            a+=(A[j]+i)%(n+1);
        }
        if(z) ans=max(a,ans);
    }
    cout<<max(ll(0),sum-ans)<<"\n";
}
