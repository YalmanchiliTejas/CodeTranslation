#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
 
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    bool end=false;
    while(!end){
        end=true;
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt += a[i]/n;
        }
        for(int i=0;i<n;i++){
            ll t=a[i]/n;
            a[i] -= t*n - cnt + a[i]/n;
            if(a[i]>=n) end=false;
        }
        ans += cnt;
    }
    cout<<ans<<endl;
    
    
}
