#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

ll modinv(ll a, int b){// a/b mod MOD
    ll res=1;
    int n=MOD-2;
    ll x=b;
    while(n>0){
        if(n&1==1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        n>>=1;
    }
    res*=a;
    res%=MOD;
    return res;
}


int main() {
    int N;cin>>N;
    ll sumA=0;
    ll sumA2=0;
    for (int i = 0; i < N; i++){
        ll A;cin>>A;
        sumA+=A;sumA%=MOD;
        sumA2+=A*A;sumA2%=MOD;
    }
    ll ans=sumA*sumA-sumA2;ans%=MOD;
    ans=modinv(ans,2);
    cout<<ans<<endl;
}