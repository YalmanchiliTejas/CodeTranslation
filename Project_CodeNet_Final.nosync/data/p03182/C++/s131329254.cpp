#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll n,m,N;
vector<l_l> interval[220000];
vl node,sum;
void init(){
    N=1;
    while(N<n)N*=2;
    node.resize(2*N,0);
    sum.resize(2*N,0);
}
void setval(ll l,ll r,ll val,ll bottom=0,ll top=-1,ll pos=1){
    if(top<0)top=N;
    if(r<=bottom||top<=l)return;
    if(l<=bottom&&top<=r){
        sum[pos]+=val;
        return;
    }
    ll mid=(top+bottom)/2;
    setval(l,r,val,bottom,mid,2*pos);
    setval(l,r,val,mid,top,2*pos+1);
    node[pos]=max(node[2*pos]+sum[2*pos],node[2*pos+1]+sum[2*pos+1]);
}
ll getmax(ll l,ll r,ll bottom=0,ll top=-1,ll pos=1){
    if(top<0)top=N;
    if(r<=bottom||top<=l)return -LINF;
    if(l<=bottom&&top<=r)return node[pos]+sum[pos];
    ll mid=(bottom+top)/2;
    ll vl=getmax(l,r,bottom,mid,2*pos);
    ll vr=getmax(l,r,mid,top,2*pos+1);
    return max(vl,vr)+sum[pos];
}
int main(){
    cin>>n>>m;
    n+=2;
    init();
    rep(i,m){
        ll l,r,a;cin>>l>>r>>a;
        interval[r].pb({l,a});
    }
    ll ans=0;
    rrep(i,n){
        ll mx=getmax(0,i);
        //cout<<mx<<endl;
        setval(i,i+1,mx);
        for(auto next:interval[i]){
            setval(next.fi,i+1,next.se);
        }
    }
    cout<<getmax(0,n+1)<<endl;
    return 0;
}