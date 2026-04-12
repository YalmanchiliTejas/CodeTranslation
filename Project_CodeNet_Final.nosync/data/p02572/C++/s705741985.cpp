#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const ll mod = 1e9+7;
ll a[200005];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll sum = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans+=a[i]*sum;
        ans%=mod;
        sum+=a[i];
        sum%=mod;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
