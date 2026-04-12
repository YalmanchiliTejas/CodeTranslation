#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n;
Vi a;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n;
    a.resize(n);
    rep(i,n){
        cin>>a[i];
    }
    matrix dp;
    if(n%2==0){
        dp.resize(2,Vi(n+1,-INF));
    }else{
        dp.resize(3,Vi(n+1,-INF));
    }
    dp[0][0] = 0;
    rep(i,n){
        rep(j,dp.size()){
            ll now = (i-j)/2;//now個選んでる
            if(now<0)continue;
            if(dp[j][i]==-INF)continue;
            repi(k,j,dp.size()){
                if(i+k-j+1 < n)chmax(dp[k][i+k-j+2],dp[j][i]+a[i+1+k-j]);
                if(now==0)dp[k][i+k-j+1] = dp[j][i] + a[i+k-j];
            }
        }
    }
    ll ans = -INF;
    rep(i,dp.size()){
        chmax(ans,dp[i][n+i-dp.size()+1]);
    }
    print(ans);
    return 0;
}