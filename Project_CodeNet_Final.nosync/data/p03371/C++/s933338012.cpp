#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n,m) for(ll i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) for(ll i=(n);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<ll,ll>;
using PP=pair<ll,P>;
using vp=vector<P>;
using vpp=vector<PP>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
int main(){
    int a,b,c,n,m;
    cin>>a>>b>>c>>n>>m;
    ll ans=INF;
    REPR(i,max(n,m)){
        int p=max(0LL,n-i);
        int q=max(0LL,m-i);
        chmin(ans,p*a+q*b+i*2*c);
    }
    cout<<ans<<endl;
    return 0;
}