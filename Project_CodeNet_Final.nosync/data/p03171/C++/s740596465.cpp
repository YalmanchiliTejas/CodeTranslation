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
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll dp[n][n];
    rep(i,0,n-1)dp[i][i]=a[i];
    rep(j,2,n){
        rep(i,0,n-j){
            dp[i][i+j-1]=max(a[i+j-1]-dp[i][i+j-2],a[i]-dp[i+1][i+j-1]);
            /*if((n-j)%2==0){
                dp[i][i+j-1]=max(a[i+j-1]-dp[i][i+j-2],a[i]-dp[i+1][i+j-1]);
            }else{
                dp[i][i+j-1]=min(a[i+j-1]-dp[i][i+j-2],a[i]-dp[i+1][i+j-1]);
            }*/
        }
    }
    cout<<dp[0][n-1]<<endl;
    
    return 0;
}
