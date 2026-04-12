#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
string alp="abcdefghijklmnopqrstuvwxyz";
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll i_3=998244353;

int main(){
    ll n,s;cin>>n>>s;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    ll dp[s+1][n+1][3];
    rep(i,0,s){
        if(i==0){
            dp[i][0][0]=1;
            dp[i][0][1]=0;
            dp[i][0][2]=0;
        }else{
            dp[i][0][0]=0;
            dp[i][0][1]=0;
            dp[i][0][2]=0;
        }
    }
    rep(i,1,n){
        rep(j,0,s){
            if(j==0){
                dp[j][i][0]=1;
            }else{
                dp[j][i][0]=0;
            }
            if(j-a[i]>=0){
                dp[j][i][1]=(dp[j][i-1][0]+dp[j][i-1][1]+dp[j-a[i]][i-1][0]+dp[j-a[i]][i-1][1])%i_3;
            }else{
                dp[j][i][1]=(dp[j][i-1][0]+dp[j][i-1][1])%i_3;
            }
            if(j<s){
                dp[j][i][2]=0;
            }else{
                if(j-a[i]>=0){
                    dp[j][i][2]=(dp[j][i-1][2]+dp[j][i-1][1]+dp[j-a[i]][i-1][1]+dp[j-a[i]][i-1][0])%i_3;
                }else{
                    dp[j][i][2]=(dp[j][i-1][2]+dp[j][i-1][1])%i_3;
                }
            }
        }
    }
    /*
    rep(i,0,s){
        rep(j,0,n){
            rep(k,0,2){
                cout<<dp[i][j][k];
            }
            if(j<n){
                cout<<' ';
            }else{
                cout<<endl;
            }
        }
    }*/
    cout<<dp[s][n][2]<<endl;
    
    
    return 0;
}




