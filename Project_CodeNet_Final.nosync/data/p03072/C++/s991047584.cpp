#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    ll ans=1,cur=a[0];
    for(ll i=1;i<n;i++)if(a[i]>=cur)ans++,cur=a[i];
    cout<<ans;
}
