//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
#define i_5 i_7-2

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
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
#define fi first
#define se second
#define endl "\n"
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

int main(){fastio
    ll n;cin>>n;
    string s;cin>>s;
    ll p[1<<(n+1)];
    rep(i,0,(1<<n)-1){
        cin>>p[i];
        p[i]--;
    }
    rep(i,0,(1<<n)-1){
        p[i+(1<<n)]=p[i];
    }
    ll dp[1<<n][n+1];
    rep(j,0,n){
        if(j==0){
            rep(i,0,(1<<n)-1){
                dp[i][j]=p[i];
            }
        }else{
            rep(i,0,(1<<n)-1){
                ll x=dp[i][j-1];
                ll posy=(i+(1<<(j-1)))&((1<<n)-1);
                ll y=dp[posy][j-1];
                if(x>y)swap(x,y);
                if(s[y-x-1]=='0'){
                    dp[i][j]=x;
                }else{
                    dp[i][j]=y;
                }
            }
        }
    }
    rep(i,0,(1<<n)-1){
        cout<<dp[i][n]+1<<endl;
    }
    
    
    return 0;
}

