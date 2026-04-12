#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod2=1000000007;
ll mod=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
int main(){
    ll n;cin>>n;
    ll a[n];
    ll sum=0;
    rep(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    //cout<<sum-n*(n-1)<<" "<<sum<<endl;return 0;
    for(ll i=max((ll)0,sum-n*(n-1));i<sum+1;i++){
        ll cnt=0;
        rep(j,0,n){
            ll r=a[j]+i-n+1;
            if(r<=0)continue;
            cnt+=r/(n+1);
            if(r%(n+1)!=0)cnt++;
        }
        //cout<<i<<endl;
        if(cnt==i){
            cout<<i<<endl;
            return 0;
        }
    }
    
}
