#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    int n;
    cin>>n;
    lli a[n];
    
    lli mod =1e9+7;
    lli b[n];
    rep(i,n){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i] = (a[i]+b[i-1])%mod;
    }
    lli ans = 0;
    for(int i=0;i<n;i++){

            lli x =b[n-1]-b[i];
            if(x<0)
                x+=mod;
            ans+=(a[i]*x);
            ans%=mod;
        
    }
    cout<<ans<<endl;
    


}
int main()
{
    int t;
    //cin>>t;
    
    t=1;
    while(t--){
        solve();
    }
}
