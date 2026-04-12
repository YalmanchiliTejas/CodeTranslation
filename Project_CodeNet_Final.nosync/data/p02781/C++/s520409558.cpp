//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
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
////////////////////////////

ll comb(ll n,ll k){
    ll res=1;
    rep(i,0,k-1){
        res*=(n-i);
    }
    rep(i,1,k){
        res/=i;
    }
    return res;
}

int main(){fastio
    string s;cin>>s;
    ll n,k;
    n=s.size();
    cin>>k;
    ll ans=0;
    if(n-1>=k)ans+=comb(n-1,k)*(ll)pow(9,k);
    ll top=s[0]-'0';
    if(n-1>=k-1)ans+=(top-1)*comb(n-1,k-1)*(ll)pow(9,k-1);
    string ze;
    ze+=s[0];
    rep(i,1,n-1)ze+='0';
    if(k==1){
        string t=ze;
        if(t<=s)ans++;
    }else if(k==2){
        rep(i,1,n-1){
           
                rep(xi,1,9){
                    
                        string t=ze;
                        t[i]=char('0'+xi);
                        if(t<=s)ans++;
                    
                }
            
        }
    }else{
        rep(i,1,n-1){
            rep(j,i+1,n-1){
                rep(xi,1,9){
                    rep(xj,1,9){
                        string t=ze;
                        t[i]=char('0'+xi);
                        t[j]=char('0'+xj);
                        if(t<=s)ans++;
                    }
                }
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
