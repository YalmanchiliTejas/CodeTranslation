#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////

vector<vector<ll>> R;

vector<ll> Desk;
bool Bol[100000];
ll Counter;
void Rep(ll x){
    if(Desk.size()==x){
        R.pb(Desk);
        Counter++;
        return ;
    }
    rep(i,1,x){
        if(!Bol[i]){
            Desk.pb(i);Bol[i]=true;
            Rep(x);
            Desk.pop_back();Bol[i]=false;
        }
    }
}

int main(){
    ll n,m;cin>>n>>m;
    ll a[m],b[m];
    bool d[n+1][n+1];
    rep(i,1,n)rep(j,1,n)d[i][j]=false;
    rep(i,0,m-1){
        cin>>a[i]>>b[i];
        d[a[i]][b[i]]=true;
        d[b[i]][a[i]]=true;
    }
    Rep(n);
    bool c;
    ll ans=0;
    rep(i,0,R.size()-1){
        c=true;
        if(R[i][0]!=1){
            continue;
        }
        rep(j,0,n-2){
            if(!d[R[i][j]][R[i][j+1]]){
                c=false;
            }
        }
        if(c)ans++;
        
    }
    cout<<ans<<endl;
    
    return 0;
}
