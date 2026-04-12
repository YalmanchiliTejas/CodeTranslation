#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll mod=1000000007;

int main(){

    ll N;
    cin>>N;
    vector<ll> A(N,0);
    vector<ll> B(N,0);
    

    for(int i=0;i<N;++i){
        cin>>A[i];
    }

    ll ans=0;
    B[N-1]=A[N-1];

    for(ll i=0;i<N-1;++i){
        B[N-2-i]=(B[N-1-i]+A[N-2-i])%mod;
    }

/*
    for(int i=0;i<N;++i){
        cout<<B[i]<<" ";
    }
    cout<<endl;
*/
    for(ll i=0;i<N-1;++i){
        //cout<<A[i]<<":"<<B[N-1-i]<<endl;

        ans=(ans+A[i]*B[i+1])%mod;
    }

    cout<<ans<<endl;


    
}