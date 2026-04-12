#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef map<int, int> mi;
typedef set<int> si;
#define VV(T) vector<vector< T > >

#define rep(i, n) REP(i, 0, n)                              // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++)             // x, x + 1, ..., n-1
#define invrep(i, n) for(int i = (n)-1; i >= 0; i--)        // n-1, n-2, ..., 0
#define invREP(i, x, n) for(int i = (n)-1; i >= (x; i--)    // n-1, n-2, ..., x
#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(v) (v).begin() , (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define PB push_back

#define COUT(x) cout << (x) << endl
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl

int G[10][10] = {{0}};

int main(){
    int N, M; cin >> N >> M;
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a][b]= G[b][a] = 1;
    }

    vi v;
    rep(i, N) v.push_back(i);

    int ans = 0;
    do{
        if(v[0] != 0) continue; // 頂点１以外は枝切り
        bool f = true;
        REP(i, 1, N){
            if(!G[v[i]][v[i - 1]]) f = false; // 経路が存在しなければ出る
        }
        if(f) ans++;
    } while(next_permutation(ALL(v)));

    COUT(ans);
}