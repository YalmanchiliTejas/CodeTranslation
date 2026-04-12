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

string n;
ll k;
ll dp[110][110][2];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    cin>>n>>k;
    rep(i,110){
        rep(j,4){
            rep(l,2){
                dp[i][j][l] = 0;
            }
        }
    }
    dp[1][1][1]=n[0]-'0'-1;
    dp[1][1][0]=1;
    dp[1][0][1]=1;

    repi(i,1,n.size()){
        rep(j,k+1){
            rep(l,2){
                if(dp[i][j][l]!=0){
                    ll now = dp[i][j][l];
                    if(j==k){
                        dp[i+1][j][l]+=now;
                    }else if(l==0){
                        if(n[i]=='0'){
                            dp[i+1][j][0] += now;
                            continue;
                        }
                        dp[i+1][j+1][1] += now *(n[i]-'0'-1);
                        dp[i+1][j][1] += now;
                        dp[i+1][j+1][0] += now;
                    }else{
                        dp[i+1][j+1][1] += now*9;
                        dp[i+1][j][1] += now;
                    }
                }
            }
        }
    }
    print(dp[n.size()][k][0]+dp[n.size()][k][1]);
    return 0;
}