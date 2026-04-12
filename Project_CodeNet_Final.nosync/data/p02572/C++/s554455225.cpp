#include<iostream>
using namespace std;
#define int             long long
const int N = 2e5 + 5, mod = 1e9+7;
int a[N],n,sum,ans;
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }

    for(int i=0;i<n-1;i++){
        sum=(sum+mod-a[i])%mod;
        ans = ans + (sum*a[i])%mod;
        ans%=mod;
    }

    cout<<ans;
}
