#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N);
    for(ll i=0;i<N;i++){
        cin>>A.at(i);
    }
    ll tmp = 0;
    ll mod = 1000000007;
    ll sum = accumulate(A.begin(),A.end(),0LL);
    ll ans = 0;
    for(ll i = 0;i<N-1;i++){
        sum = sum-A.at(i);
        tmp = sum%mod;
        tmp = tmp*A.at(i);
        tmp = tmp%mod;
        ans = ans + tmp;
        ans %=mod;
    }
    // for(ll i=0;i<N-1;i++){
    //     for(ll j=i+1;j<N;j++){
    //         ans += A.at(i)*A.at(j);
    //         ans=ans%mod;
    //     }
    // }
    cout<<ans;
}