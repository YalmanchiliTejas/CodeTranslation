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
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);




int main(){
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    deque<ll> d;
    rep(i,0,n-1){
        if(i==0){
            d.push_front(a[i]);
        }else{
            ll l=-1,r=d.size();
            ll mid;
            while(r-l>1){
                mid=(r+l)/2;
                if(d[mid]<a[i]){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            if(l==-1){
                d.push_front(a[i]);
            }else{
                d[l]=a[i];
            }
        }
    }
    cout<<d.size()<<endl;
    
    
    
    return 0;
}


