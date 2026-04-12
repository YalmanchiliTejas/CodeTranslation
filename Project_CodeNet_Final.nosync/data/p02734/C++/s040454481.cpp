#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
typedef stack<ll> ST;
typedef queue<ll> QUE;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=998244353;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

int main(){
    int N,S; cin>>N>>S;
    vec A(N);
    rep(i,N) cin>>A[i];
    vector<mat> dp(3010,mat(3010,vec(2)));
    rep(i,S+1){
        rep(j,2){
            dp[0][i][j]=0;
        }
    }
    rep(i,N){
        rep(j,S+1){
            if(j-A[i]>0){
                dp[i+1][j][0]=(dp[i][j][0]+dp[i][j-A[i]][0])%mod;
                dp[i+1][j][1]=(dp[i][j][1]+((N-i)*dp[i][j-A[i]][0])%mod)%mod;
            }
            else if(j==A[i]){
                dp[i+1][j][0]=(dp[i][j][0]+i+1)%mod;
                dp[i+1][j][1]=(dp[i][j][1]+(N-i)*(i+1))%mod;
            }
            else{
                rep(k,2){
                    dp[i+1][j][k]=dp[i][j][k];
                }
            }
        }
    }
    cout<<dp[N][S][1]<<endl;
    return 0;
}