#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
const long long int sMod = 998244353;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
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

Vi nxt(100030);
Vi seen(100030);
Vi res(100030);

void solve(){
    ll n,x,m;
    cin >> n >> x >> m;
    rp(i,100020){
        nxt[i]=i*i%m;
    }
    ll pos=x;
    ll ctr=1;
    ll sum=0;
    while(seen[pos]==0){
        if(ctr==n+1){
            print(sum);
            return;
        }
        seen[pos]=ctr;
        sum+=pos;
        res[ctr]=sum;
        pos=nxt[pos];
        ctr++;
    }
    sum+=(res[ctr-1]-res[seen[pos]-1])*((n+1-ctr)/(ctr-seen[pos]));
    ll rest=(n+1-ctr)%(ctr-seen[pos]);
    rp(i,rest){
        sum+=pos;
        pos=nxt[pos];
    }
    print(sum);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}