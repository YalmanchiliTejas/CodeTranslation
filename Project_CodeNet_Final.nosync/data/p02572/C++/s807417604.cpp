#include"bits/stdc++.h"
using namespace std;

int main(){
    int N;
    long long int A[200001],count=0,ans=0;
    long long int mod=1000000007;
    cin>>N;
    for(int i=0;i<N;i++)    cin>>A[i];

    for(int i=N-1;i>0;i--){
        count=(count+A[i])%mod;
        ans=(ans+count*A[i-1])%mod;
    }

    cout<<ans<<endl;
    return 0;
}
