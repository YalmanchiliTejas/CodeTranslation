//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,ans=0; cin>>n;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    if(n%2==0){
        vector<ll> sum(n/2+1,0);
        ll cur=0;
        rep(i,n/2){
            sum[i+1]=sum[i]+a[2*i]-a[2*i+1];
            ans+=a[2*i+1];
            cur=max(cur,sum[i+1]);
        }
        cout<<ans+cur<<endl;
    }
    else{
        vector<ll> sum(n/2+1,0);
        ans+=a.back();
        rep(i,n/2){
            sum[i+1]=sum[i]+a[2*i+1]-a[2*i];
            ans+=a[2*i];
        }
        ll cur=-INF;
        set<ll> s;
        rep(i,n/2+1){
            s.insert(sum[i]);
            ll k=*begin(s);
            cur=max(cur,sum[i]-k-a[2*i]);
        }
        cout<<ans+cur<<endl;
    }
}
