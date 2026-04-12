#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n;
ll calc(vl a){
    ll ans=0;
    while(true){
        ll dd=0;
        for(int i=0;i<n;i++){
            dd+=a[i]/n;
        }
        if(dd==0)break;
        ans+=dd;
        for(int i=0;i<n;i++){
            a[i]=(a[i]%n)+dd-a[i]/n;
        }
    }
    return ans;
}
int main(){
    cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    cout<<calc(a)<<endl;
    return 0;
}