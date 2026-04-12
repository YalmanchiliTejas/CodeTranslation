#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll s[n];rep(i,0,n)cin>>s[i];
    ll ans=0;
    rep(i,1,n-1){
        if(n/2==i)break;
        ll x=0,y=0;
        ll nowx=0,nowy=n-1;
        
        for(;;){
            nowx+=i;
            nowy-=i;
            if(nowy<=i)break;
            if(nowx==nowy)break;
            if(nowx>=n-1)break;
            if(nowx>nowy&&nowx-nowy==i)break;
            x+=s[nowx];
            y+=s[nowy];
            ans=max(ans,x+y);
            
        }
    }
    cout<<ans<<endl;
}
