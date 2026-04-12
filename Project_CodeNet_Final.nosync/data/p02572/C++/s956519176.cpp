#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf =2e5+9,mod = 1e9+7;
ll n,a[inf];
int main(){

    cin>>n;
    ll sum = 0,ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans = (ans + (sum*a[i] )%mod )%mod;
        sum = (sum + a[i])%mod;
    }
    cout<<ans<<endl;
}
