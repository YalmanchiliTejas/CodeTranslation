#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N,K;
    cin>>N>>K;
    ll ans = 0;
    if(K==0)
        ans = N*N;
    else{
    for(ll i=K+1; i<=N; i++){
        if(N%i >=K){
            ans+= N%i-K+1+ (i-K)*(N-(N%i))/i;
        }
        else{
            ans+= (i-K)*(N-(N%i))/i;
        }
    }
    }
    cout<<ans<<endl;

    return 0;
}
