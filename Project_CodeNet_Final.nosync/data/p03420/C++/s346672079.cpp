#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans=n*n;

    rep(i,n){
        //cout << ans << endl;
        if((i+1)<=k){
            ans-=n;
        }
        else{
        ans-=(n/(i+1))*k;
        if(n%(i+1)>=k){
            ans-=(k-1);
        }
        else{
            ans-=(n%(i+1));
        }
        }

    }

    if(k==0){
        ans=n*n;
    }
    cout << ans << endl;
    

    return 0;
}