#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vp;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define MMOD(i) ((i%MOD)+MOD)%MOD;
#define all(v) v.begin() , v.end()
#define vec(i,j) vector<vector<ll>>(i,vector<ll>(j,0))
#define input(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF=99999999999999;
const ll MOD=1000000007;
const ll MAX_N=100010;
ll a,b,c,d,e,f,x,y,z,k,m,n,l,h,w,t,p,q,ans=0;
vl v,vv;
string s1,s2;
ll solve(){
    vv.push_back(-v[0]);
    for(ll i=1;i<n;i++){
        a=upper_bound(all(vv),-v[i])-vv.begin();
        if(a==vv.size()){
            vv.push_back(-v[i]);
        }
        else{
            vv[a]=-v[i];
        }
        /*cout<<vv.size()<<endl;
        rep(k,vv.size()){
        	cout<<vv[k]<<" ";
        }
        cout<<endl;*/
    }
    return vv.size();
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    input(v,n);
    cout<<solve()<<endl;
 
}