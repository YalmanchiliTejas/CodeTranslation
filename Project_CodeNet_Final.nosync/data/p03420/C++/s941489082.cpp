#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    ll ans = 0;
    for(int b=k+1; b<=n; b++){
        ans += (b-k)*(n/b);
        int r = n-b*(n/b);
        ans += max(0,r-k+1);
    }
    if(k==0)ans-=n;
    cout<<ans<<endl;
    return 0;
}