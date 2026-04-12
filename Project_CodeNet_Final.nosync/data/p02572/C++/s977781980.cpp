#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    int n;
    cin>>n;
    lli a[n];
    lli sum =0 ;
    lli mod =1e9+7;
    rep(i,n)
    {
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }
    lli ans =0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        if(sum<0)
        sum+=mod;
        ans+=(sum*a[i]);
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