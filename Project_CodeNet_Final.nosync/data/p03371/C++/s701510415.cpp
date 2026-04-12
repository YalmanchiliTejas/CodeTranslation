#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = INT64_MAX;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;
using Vi = vector<long long int>;
typedef pair<int, int> P; typedef pair<ll, ll> PLL;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i=0;i<N;i++)
auto max(auto x,auto y){if(x>y){return x;}else{return y;}}
auto min(auto x,auto y){if(x>y){return y;}else{return x;}}
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
typedef vector<vector<ll> > matrix;
void princ(auto x){cout<<x<<" ";}; void print(auto x){cout<<x<<"\n";};
///////////////////////////////////////////////////////////////////////////////////

ll a,b,c,x,y;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>a>>b>>c>>x>>y;
    ll ans = 0;
    if((a+b) >= 2*c){
        ll z = min(x,y);
        ans += 2*c*(z);
        x -= z; y -= z;
        ans += x*min(2*c,a);
        ans += y*min(2*c,b);
    }else{
        ll z = min(x,y);
        ans += a*z;
        ans += b*z;
        x -= z; y -= z;
        ans += x*min(2*c,a);
        ans +=y*min(2*c,b);
    }
    print(ans);
    return 0;
}