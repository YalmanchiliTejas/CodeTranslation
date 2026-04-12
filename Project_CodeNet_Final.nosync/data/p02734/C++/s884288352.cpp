#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N,S;
    cin>>N>>S;
    vector<ll> A(N+1);

    A[0]=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    ll mod=998244353;
    ll ans=0;

    vector<ll> x(S+1,0);
    for(int i=0;i<N;i++){
        x[0]++;
        vector<ll> x2(S+1,0);
        for(int j=0;j<S+1;j++){
            x2[j]+=x[j];
            x2[j]%=mod;
            if(j+A[i]<=S){
                x2[j+A[i]]+=x[j];
                x2[j+A[i]]%=mod;
            }
        }
        x=x2;
        ans+=x[S];
        ans%=mod;
    }


    cout<<ans<<endl;

    return 0;
}