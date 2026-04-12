#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    ll f;
    f=x%m;
    ll k=0;
    ll a;
    a=f;
    vector <ll> c1(m,0),c2(m,0);
    c1[f]=1;
    ll ans=x;

    int cc=0;
    int r=0,r2;
    while(r==0){
        a=(a*a)%m;
        ++k;
        ans+=a;

        if(k==(n-1)){
            cc=1;
            break;
        }
        if(c1[a]==0){
            ++c1[a];
        }
        else{
            r=1;
            r2=a;
            ans-=a;
        }
    }

    if(cc==0){
    ll aa;
    ll ans2=aa;
    ll ru=1;
    aa=r2;
    ll rw=aa;
    
    aa=(aa*aa)%m;
    
    while(aa!=r2){
        rw+=aa;
        aa=(aa*aa)%m;
        
        
        ++ru;
    }

    //cout << ans << endl;
    //cout << k << " " << rw << endl;

    ans+=((n-k)/ru)*rw;

    aa=r2;
    rep(i,(n-k)%ru){
        ans+=aa;
        aa=(aa*aa)%m;
    }
    }



    cout << ans << endl;
    
    

    return 0;
}