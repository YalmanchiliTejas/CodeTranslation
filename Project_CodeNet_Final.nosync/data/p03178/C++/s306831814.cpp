#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef pair<ll,P> pp;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tup;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}

int main(){
    string s; ll d; cin >> s >> d;
    ll n = s.size();
    ll dp[n+1][d][2];
    rep(i,n+1) rep(j,d) rep(k,2) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i,n){
        ll t = s[i] - '0';
        rep(j,d){
            rep(k,t) rep(l,2) dp[i+1][(j+k)%d][1] += dp[i][j][l];
            rep(k,2) dp[i+1][(j+t)%d][k] += dp[i][j][k];
            REP(k,t+1,10) dp[i+1][(j+k)%d][1] += dp[i][j][1];
        }
        rep(j,d) rep(k,2) dp[i+1][j][k] %= mod;
    }
    ll ans = dp[n][0][0]+dp[n][0][1];
    if(ans==0) cout << mod-1 << endl;
    else cout << (ans-1)%mod << endl;
}