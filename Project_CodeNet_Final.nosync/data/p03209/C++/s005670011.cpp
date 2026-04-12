#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
#define INF (1<<30)
#define LINF (1ll<<60ll)
#define MOD 1000000007
#define pb(a) push_back(a)
#define _overload4(_1,_2,_3,_4,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=a, i##_len=(b); i<i##_len; ++i)
#define _repis(i,a,b,s) for(int i=a, i##_len(b); i<i##_len; i+=s)
#define REP(...) _overload4(__VA_ARGS__,_repis,_repi,_rep,)(__VA_ARGS__)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define REPARR(i, v) for(int i = 0;i < sz(v);++i)
#define all(vec) (vec.begin()),(vec.end())
#define sz(x) ((int)(x).size())
#define bit(n) (1ll<<(n))
#define d(a) cerr<<#a<<":"<<a<<endl
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define yes(n) cout<<((n)?"yes":"no")<<endl
#define poss(n) cout<<((n)?"possible":"impossible")<<endl
#define Poss(n) cout<<((n)?"Possible":"Impossible")<<endl
#define POSS(n) cout<<((n)?"POSSIBLE":"IMPOSSIBLE")<<endl

ll l(ll n){
    return (4ll<<n)-3;
}
ll f_(ll,ll);
ll f(ll n,ll x){
//ll r=f_(n,x);cerr<<n<<","<<x<<","<<r<<endl;return r;}ll f_(ll n,ll x){
    if(x<=n)return 0;
    if(n<1)return 1;
    if(l(n)==x)return f(n-1,l(n-1))*2+1;
    
    
    if(x<=l(n-1)+1)return f(n-1,x-1);
    if(x==l(n-1)+2)return f(n-1,l(n-1))+1;
    if(l(n)==x-1)return f(n-1,l(n-1))*2+1;
    //cout<<">>>"<<x-2-l(n-1)<<endl;
    if(x-2-l(n-1)<0)while(1){};
    return f(n-1,l(n-1))+f(n-1,x-2-l(n-1))+1;
}

int main(){
    /*REP(i,1,50){
        cout<<i<<","<<l(i)<<endl;
    }*/
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    cout<<f(n,x)<<endl;
    return 0;
}
