#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long n;
    cin>>n;
    vector<long long>a(n+1);

    rep2(i,n){
        cin>>a[i];
        a[i]%=mod;
    }

    long long s[n+1];
    s[0]=0;
    rep2(i,n){
        s[i]=s[i-1]+a[i];
    }
    long long ans=0;
    rep2(i,n-1){
        ans+=(a[i]*((s[n]-s[i])%mod))%mod;
        ans%=mod;
    }
    //rep2(i,n)cout<<s[i]<<" ";

    cout<<ans<<endl;

    return 0;

}
/*


*/
