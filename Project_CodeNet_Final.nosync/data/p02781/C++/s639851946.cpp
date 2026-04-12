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
    string n;
    int k;
    cin >> n >> k;
    int s=n.size();
    ll dp[2][s+1][k+2];//kk==1ならn未満が保証される
    rep(kk,2){
        rep(i,s+1){
          	rep(j,k+1){
              	dp[kk][i][j]=0;
            }
        }
    }
    dp[0][0][0]=1;
    rep(i,s){
        int N=n[i]-'0';
        rep(kk,2){
            int T=9;
            if(kk==0){
                T=N;
            }
            rep(j,k+1){
                rep(d,T+1){
                    int NZ=0;
                    if(d!=0){
                        NZ++;
                    }
                    dp[kk||(d<T)][i+1][j+NZ]+=dp[kk][i][j];
                }
            }
        }
    }
    cout << dp[0][s][k] + dp[1][s][k] << endl;
}