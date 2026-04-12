#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<n;i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

using P = pair<ll,ll>;
ll ans1,ans2;

int main(){
    int N; cin >> N;
    vector<P> a(N);
    ll mx=-1,mn=(1ll<<32);
    rep(i,N){
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
        chmax(mx,a[i].se);
        chmin(mn,a[i].fi);
    }
    sort(all(a));

    ll Rmax = mx;
    // Bmin = mn
    {
        ll Bmin = mn;
        vector<int> x,y;
        rep(i,N) x.pb(a[i].fi);
        rep(i,N) y.pb(a[i].se);
        ll Bmax = *max_element(all(x));
        ll Rmin = *min_element(all(y));
        ans1 = (Rmax-Rmin) * (Bmax-Bmin);
    }

    // Rmin = mn
    {
        ans2 = 1e9 * 1e9;
        ll Rmin = mn;
        vector<ll> ymin(N,1ll<<29),ymax(N,0);
        vector<ll> rymin(N,1ll<<29),rymax(N,0);
        ymin[0] = ymax[0] = a[0].se;
        for(int i=1;i<N;i++){
            ymin[i] = min(ymin[i-1],a[i].se);
            ymax[i] = max(ymax[i-1],a[i].se);
        }
        rymin[N-1] = rymax[N-1] = a[N-1].se;
        for(int i=N-2;i>=0;i--){
            rymin[i] = min(rymin[i+1],a[i].se);
            rymax[i] = max(rymax[i+1],a[i].se);
        }

        for(int i=0;i<N;i++){
            ll Rmin = a[0].fi;
            ll Rmax = max(a[i].fi,rymax[i+1]);
            ll Bmin = min(a[i+1].fi,ymin[i]);
            ll Bmax = max(a[N-1].fi,ymax[i]);
            if(Rmin == mn and Rmax == mx){
                chmin(ans2,(Rmax-Rmin)*(Bmax-Bmin));
            }
        }
    }

    cout << min(ans1,ans2) << endl;
}
