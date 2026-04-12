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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main(){fastio
    ll n,x,m;cin>>n>>x>>m;
    map<ll,ll> mp;
    ll ini=-1;
    vector<ll> sum;
    ll now=x;
    ll counter=0;
    ll S=0;
    
    while(true){
        mp[now]=counter;
        S+=now;
        sum.pb(S);
        counter++;
        now=(now*now)%m;
        auto it=mp.find(now);
        if(it!=mp.end()){
            break;
        }
    }
    
    ll r_i=mp[now];
    ll r_f=now;
    ll r_sum;
    if(r_i>0){
        r_sum=sum[counter-1]-sum[r_i-1];
    }else{
        r_sum=sum[counter-1];
    }
    ll r_num=counter-r_i;
    
    ll ans=0;
    now=x;
    rep(i,0,min(r_i,n-1)){
        ans+=now;
        now=(now*now)%m;
    }
    if(n-1<=r_i){
        cout<<ans<<endl;
        return 0;
    }
    ll r_c=(n-r_i-1)/r_num;
    ll amari=(n-r_i-1)%r_num;
    ans+=(r_c*r_sum);
    
    now=r_f;
    now=(now*now)%m;
    rep(i,0,amari-1){
        ans+=now;
        now=(now*now)%m;
    }
    cout<<ans<<endl;
    
    return 0;
}



