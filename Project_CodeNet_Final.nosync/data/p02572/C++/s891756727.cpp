#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int mod = 1000000007;

int main(){
    ll N; cin>>N;
    vector<ll> A(N),a(N);
    ll sum=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
        sum%=mod;
    }
    ll ans=0;
    for(ll i=0;i<N-1;i++){
        sum -=A[i];
        if(sum<0)  sum+=mod;

        ans+=A[i]*sum;
        ans%=mod;
    }
    cout<<ans<<endl;
}