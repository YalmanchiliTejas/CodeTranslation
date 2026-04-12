#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    ll mod=1e9+7;
    int N;
    cin>>N;
    vector<ll> A(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
        sum%=mod;
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        sum-=A[i];
        sum+=mod;
        sum%=mod;
        ans+=A[i]*sum;
        ans%=mod;
    }

    cout<<ans<<endl;

    return 0;
}