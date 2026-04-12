#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_intで宣言
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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////


ll a[51];
ll pa[51];

ll ans=0;
void po(ll k,ll pos){
    if(k==0){
        if(pos==1)ans++;
        return;
    }
    if(pos<=1)return;
    if(pos<=1+a[k-1]){
        po(k-1,pos-1);
    }else if(pos==2+a[k-1]){
        ans++;
        ans+=pa[k-1];
    }else{
        if(pos==a[k])pos--;
        ans+=1+pa[k-1];
        po(k-1,pos-2-a[k-1]);
    }
    
}


int main(){
    ll n,x;cin>>n>>x;
    
    a[0]=1;
    rep(i,1,50){
        a[i]=2*a[i-1]+3;
    }
    pa[0]=1;
    rep(i,1,50){
        pa[i]=2*pa[i-1]+1;
    }
    po(n,x);
    cout<<ans<<endl;


    return 0;
}
