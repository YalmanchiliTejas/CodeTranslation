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

int main(){fastio
    string k;cin>>k;
    ll d;cin>>d;
    ll dp[k.size()+1][d];
    dp[k.size()][0]=1;
    rep(i,1,d-1)dp[k.size()][i]=0;
    rep(i,0,k.size()-1){
        rep(j,0,d-1){
            dp[i][j]=0;
        }
    }
    /*
    rep(i,0,min(stoll(k),9)){
        dp[k.size()-1][i%d]++;
        dp[k.size()-1][i%d]=dp[k.size()-1][i%d]%i_7;
    }
    if(stoll(k)<=9){
        cout<<max(0,dp[0][0]-1)<<endl;
        return 0;
    }*/
    for(ll i=(ll)k.size()-1;i>=0;i--){
        rep(j,0,d-1){
            rep(k,0,9){
                dp[i][j]=mod(dp[i][j]+dp[i+1][((j-k)%d+d)%d]);
            }
        }
    }
    /*
    rep(i,0,d-1){
        rep(j,0,k.size()){
            cout<<dp[j][i]<<' ';
        }
        cout<<endl;
    }*/
    ll ans=0;
    ll tot=0;
    rep(i,0,k.size()-1){
        rep(j,0,(ll)(k[i]-'0')-1){
            ans=mod(ans+dp[i+1][((-(tot+j))%d+d)%d]);
        }
        tot=(tot+(k[i]-'0'))%d;
    }
    if(tot%d==0){
        ans++;
    }
    cout<<mod(ans-1)<<endl;
    
    
    return 0;
}
