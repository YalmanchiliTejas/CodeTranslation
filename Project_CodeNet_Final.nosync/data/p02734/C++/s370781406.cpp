//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,S;
    cin >> N >> S;
    vl A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll dp[N+1][S+1][3];
    rep(i,N+1){
        rep(j,S+1){
          	rep(k,3){
            dp[i][j][k]=0;
            }
        }
    }
    dp[0][0][0]=1;
    FOR(i,1,N+1){
        rep(j,S+1){
          	dp[i][j][0]+=dp[i-1][j][0];
          	dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][1];
          	dp[i][j][2]+=dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2];
          	if(j-A[i-1]>=0){
              	dp[i][j][1]+=dp[i-1][j-A[i-1]][0]+dp[i-1][j-A[i-1]][1];
              	dp[i][j][2]+=dp[i-1][j-A[i-1]][0]+dp[i-1][j-A[i-1]][1];
            }
          	rep(k,3){
              	dp[i][j][k]%=MOD2;
            }
        }
    }
  	cout << dp[N][S][2] << endl;
}