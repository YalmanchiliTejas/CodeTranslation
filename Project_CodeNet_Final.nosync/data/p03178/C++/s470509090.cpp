#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////



int main(){
    string s;ll d;cin>>s>>d;
    ll n=s.size();
    ll dp[n+1][d][2];memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    rep(i,0,n-1){
        rep(j,0,d-1){
            rep(k,0,9){
                Add(&dp[i+1][(j+k)%d][1],dp[i][j][1]);
            }
            ll t=s[i]-'0';
            rep(k,0,t-1){
                Add(&dp[i+1][(j+k)%d][1],dp[i][j][0]);
            }
            Add(&dp[i+1][(j+t)%d][0],dp[i][j][0]);
        }
    }
    ll ans=0;
    rep(i,0,1){
        Add(&ans,dp[n][0][i]);
    }
    cout<<mod(ans-1)<<endl;
    
    return 0;
}




