#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

#ifdef __LOCAL
    #include <filesystem>
    namespace fs = std::filesystem;
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

int N;
vector<pll> X;
void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path p = __FILE__;
        fs::path input,output;
        input = output = p.parent_path();
        input += string("/input/") + string(p.stem()) + string(".txt");
        output += string("/output/") + string(p.stem()) + string(".txt");
        freopen(input.c_str(), "r", stdin);
        freopen(output.c_str(), "w", stdout);
    #endif
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        X.emplace_back(x,i);
    }
    sort(begin(X),end(X));
}

int solve(){
    DBG(X)
    vector<ll> ans(N);
    for (int i = 0; i < N; i++)
    {
        if(i<N/2) ans[X[i].second]=X[N/2].first;
        else ans[X[i].second]=X[(N-1)/2].first;
    }
    for(auto a:ans) cout << a <<"\n";
    
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}
