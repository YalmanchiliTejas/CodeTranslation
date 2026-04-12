#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin>>A[i];
    
    long long mod=1e9+7,ans=0,x=0;
    for(int i=0; i<N; ++i){
        ans = (ans + A[i]*x)%mod;
        x = (x + A[i])%mod;
    }

    cout<<ans<<endl;
}