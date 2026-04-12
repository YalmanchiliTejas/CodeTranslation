#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int dx[]={1, 0, -1, 0, 1,-1, 1,-1};
int dy[]={0, 1, 0, -1, 1, 1,-1,-1};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);
static mt19937 _g(time(nullptr));
 
inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

int N,M;
vector<vector<int>> G;
void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        __output += string("/output/") + string(__p.stem()) + string(".txt");
        freopen(__input.c_str(), "r", stdin);
        freopen(__output.c_str(), "w", stdout);
    #endif
    cin >> N >> M;
    G.assign(N,vector<int>());
    for (int i = 0; i < M; i++)
    {
        int a,b; cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
}

int ans=0;
void dfs(int u, int bit){
    bit |= (1<<u);
    if(bit==((1<<N)-1)) ans++;
    for(auto v:G[u]){
        if((bit>>v)&1) continue;
        dfs(v,bit);
    }
}

int solve(){
    int bit=0;
    dfs(0,bit);
    cout << ans << endl;
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}
