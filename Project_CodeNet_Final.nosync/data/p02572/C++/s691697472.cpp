#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    std::vector<ll> A(N);
    ll sum=0,ans=0;
    const ll MOD=1000000007;
    for(ll i=0;i<N;++i){
        cin>>A[i];
        sum+=A[i];
    }
    //cout<<sum<<endl;
    for(ll i=0;i<N-1;++i){
        sum-=A[i];
        //cout<<A[i]<<"*"<<sum<<"="<<A[i]*sum<<"->"<<(A[i]*sum)%MOD<<endl;
        ans+=(A[i]*(sum%MOD))%MOD;
    }
    cout<<ans%MOD;
    
}