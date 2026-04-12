#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;

main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    ll suffixsum[n];suffixsum[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suffixsum[i]=(suffixsum[i+1]+a[i])%MOD;
    }
    ll ans=0;
    for(int i=0;i+1<n;i++){
        ans+=a[i]*suffixsum[i+1]%MOD;
        ans%=MOD;
    }
    cout<<ans<<"\n";

}