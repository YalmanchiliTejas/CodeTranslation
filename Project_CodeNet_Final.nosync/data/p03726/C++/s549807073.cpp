#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define mp make_pair
#define pb push_back
#define EB emplace_back
#define fi first
#define se second
#define all(v) ALL(v)
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr double eps = 1e-14; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int N;
vvi g;

bool matched[100010];

bool dfs(int cur,int pre){
    if(g[cur].size()==1 && pre!=-1){
        if(matched[pre]) return false;
        else{
            matched[pre] = matched[cur] = true;
            return true;
        }
    }

    for(int v : g[cur]) if(v != pre){
        if(!dfs(v,cur)) return false;
    }

    if(!matched[cur]){
        if(pre==-1 or matched[pre]) return false;
        else{
            matched[cur] = matched[pre] = true;
            return true;
        }
    }
    return true;
}

int main(){
    cin >> N;
    g = vvi(N,vi());
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    if(dfs(0,-1)){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
}
