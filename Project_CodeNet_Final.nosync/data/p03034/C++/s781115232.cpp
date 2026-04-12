#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

template<typename T>inline bool chmax(T &a,const T &b){if(a>=b){return false;}a=b;return true;}
template<typename T>inline bool chmin(T &a,const T &b){if(a<=b){return false;}a=b;return true;}

/*-------------------------------------------*/

ll n;
vector<ll> s;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n;
    s.resize(n);
    rep(i,n)cin>>s[i];

    ll ans=0;

    FOR(i,1,n){
        ll now=0,l=0,r=n-1;
        while(r>i&&(r%i||l<r)){
            now+=s[l]+s[r];
            chmax(ans,now);
            l+=i;
            r-=i;
        }
    }

    cout<<ans<<endl;
}