#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define M_PI 3.14159265358979323846

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

int dx[]={1, 0, -1, 0, 0};
int dy[]={0, 1, 0, -1, 0};
const int INT_INF = (int)(2e9);
const ll  LL_INF = (ll)(2e18);
const int NIL = -1;
static mt19937 _g(time(nullptr));
 
std::string pad(int num){ char buffer[4]; std::snprintf(buffer, sizeof(buffer), "%03d", num); return buffer;}
inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }



int main()
{
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
    string S;
    cin >> S;
    string ans = !(S=="AAA" or S=="BBB") ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}
