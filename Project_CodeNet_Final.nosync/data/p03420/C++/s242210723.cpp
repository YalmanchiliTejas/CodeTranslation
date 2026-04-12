#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    if(k==0){
        cout<<n*n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ll locans=0;
        ll s=n/i;
        ll r=n%i;
        if(k<i){
            locans+=s*(i-k);
            if(r>=k){
                locans+=r-k+1;
            }
        }
     //   cout<<locans<<" "<<i<<endl;
        ans+=locans;
    }
    cout<<ans;
    return 0;
}
