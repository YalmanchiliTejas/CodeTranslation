#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0,ans2=0;

    if(n%2==0){
        rep(i,n/2){
            ans+=2*a[n-1-i];
        }
        ans-=a[n/2];
        rep(i,n/2){
            ans-=2*a[i];
        }
        ans+=a[n/2-1];
    }
    else{
        rep(i,n/2){
            ans+=2*a[n-1-i];
            ans2-=2*a[i];
        }
        rep(i,n/2+1){
            ans-=2*a[i];
            ans2+=2*a[n-i-1];
        }
        ans+=a[n/2];
        ans+=a[n/2-1];
        ans2-=a[n/2];
        ans2-=a[n/2+1];
        ans=max(ans,ans2);
    }

    cout << ans << endl;
    

    return 0;
}