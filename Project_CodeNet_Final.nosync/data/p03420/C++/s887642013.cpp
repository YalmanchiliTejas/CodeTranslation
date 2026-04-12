#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;cin>>n>>k;
    ll ans =0;
    for(ll b=k+1;b<=n;b++){
        ans+=(b-k)*(n/b);
        ll extra = n%b - max(0ll , k-1);
        ans+=max(0ll,extra);
    }
    cout<<ans;
}