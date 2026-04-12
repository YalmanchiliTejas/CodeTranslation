#include<iostream>
#include<vector>
using namespace std;
int main(){
    int mod=1000000007;
    long long n,ih=0;
    cin>>n;
    vector<long long> a(200010,0),oj(200010,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        oj[i]=(a[i]%mod+oj[i-1]%mod)%mod;
        ih=(ih%mod+a[i]%mod)%mod;
    }
    long long sum=0;
    for(int i=1;i<n;i++){
        sum=(sum%mod+(a[i]%mod*(ih%mod+mod-oj[i]%mod))%mod)%mod;
    }
    cout<<sum%mod<<"\n";
    return(0);
}