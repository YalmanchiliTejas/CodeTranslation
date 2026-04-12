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
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n;
string s;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    string ans;
    cin>>n>>s;
    Vi v(n+1,-1);
    rep(i,2){
        rep(j,2){
            v[0] = i;
            v[1] = j;
            v.resize(n+1,-1);
            for(ll k = 1;k<n;k++){
                if(v[k]==0){
                    if(s[k]=='o'){
                        v[k+1] = v[k-1];
                    }else{
                        v[k+1] = (v[k-1]+1)%2;
                    }
                }else{//ookami
                    if(s[k]=='x'){
                        v[k+1] = v[k-1];
                    }else{
                        v[k+1] = (v[k-1]+1)%2;
                    }
                }
            }
            if(v[0]!=v[n])continue;
            if(v[0]==0){
                if(s[0]=='o'){
                    if(v[1]!=v[n-1])continue;
                }else{
                    if(v[1]==v[n-1])continue;
                }
            }else{
                if(s[0]=='o'){
                    if(v[1]==v[n-1])continue;
                }else{
                    if(v[1]!=v[n-1])continue;
                }
            }

            rep(i,n){
                if(v[i]==0)ans.pb('S');
                else ans.pb('W');
            }
            print(ans);
            return 0;
        }
    }
    print(-1);
    return 0;
}