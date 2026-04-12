#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    vector <ll> a(n+1),b(n+1);
    a[0]=1;
    b[0]=1;
    rep(i,n){
        a[i+1]=2*a[i]+3;
        b[i+1]=2*b[i]+1;
    }
    ll ans=0;
    int ii=0;
    rep(i,n+1){
        if((k>=a[n-i]+ii-2 and i!=n) or (i==n and k>=a[n-i]+ii)){
            ans+=b[n-i];
            k-=a[n-i]+ii;
            if(k>0){
                ++ans;
            }
            ii=2;
        }
        else{
            ++ii;
        }
        //cout << i << " " << ans << endl;
        
        if(k==0){
            break;
        }
    }

    cout << ans << endl;



    return 0;
}