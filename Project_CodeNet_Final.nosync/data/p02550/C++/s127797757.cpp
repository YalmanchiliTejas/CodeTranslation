#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll n,x,m;
    cin>>n>>x>>m;
 
    ll id=1;
    vector<ll> a(1000010);
    a[0]=x;
    map<ll,ll> mp;
    mp[x]++;
    ll l,r;
    ll N=n;
    while(1){
        a[id]=(a[id-1]*a[id-1])%m;
        if(mp[a[id]]>0){
            rep(j,id){
                if(a[j]==a[id]){
                    l=j;
                    r=id;
                    break;
                }                
            }
            break;
        }
        mp[a[id]]++;
        id++;
    }
    /*
    rep(i,r) cout<<a[i]<<" ";
    cout<<endl;
    
    cout<<l<<" "<<r<<endl;
    */
    ll ans=0;
    if(n<=r){
        rep(i,n) ans+=a[i];
    }
    else{
        rep(i,l) ans+=a[i];
        ll sum=0;
        for(int i=l;i<r;i++) sum+=a[i];
        n-=l;
        ans+=sum*(n/(r-l));
        ll ama=0;
        ll am=n%(r-l);
        for(int i=l;i<l+am;i++) ama+=a[i];
        ans+=ama;
    }
 
    cout<<ans<<endl;
}