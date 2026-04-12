#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define CLOCK_START clock_t chrono_clk_beg = clock()
#define CLOCK_END clock_t chrono_clk_end = clock(); cerr << (double(chrono_clk_end - chrono_clk_beg) / CLOCKS_PER_SEC) << " sec"
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
#define all(x) x.begin(), x.end()
#define INF (1LL<<30)
#define INF32 (1LL<<62)
#define F first
#define S second
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define int ll
typedef unsigned long long BITMASK; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll; typedef cc_hash_table<int, int, hash<int>> intHashTable;
struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b&1) x = (x*a) % MOD; a = (a*a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD-2)) % MOD; }
inline int ceil(int a, int b) { return (a+b-1)/b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }
void err(istringstream *iss) {} template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) { string _name; *iss >> _name; if (_name.back()==',') _name.pop_back(); cerr << _name << " = " << _val << "; ", err(iss, args ...); }
int str_replace(string& str, const string& from, const string& to, int limit = -1) { if(from.empty()) return 0; size_t start_pos = 0; int cnt = 0; while((start_pos = str.find(from, start_pos)) != std::string::npos) { str.replace(start_pos, from.length(), to); start_pos += to.length(); cnt++; if (cnt == limit) break; } return cnt; }
template<int D, typename T> struct vec : public vector<vec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string k; int d; cin >> k >> d;
    /* DP[sum][smallerAlready] is number of ways to choose digits so far, such that sum of digit modulo
    d is sum and smallerAlready says whether we have already chosen some digit smaller than in k. */
    vec<2, int> DP(d, 2, 0);
    DP[0][0] = 1;
    for (auto &ch : k)
    {
        int x = ch-'0';
        vec<2, int> newDP(d, 2, 0);
        /* Iterating over previous DP to form new DP */
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int dig = 0; dig <= 9; ++dig)
                {
                    /* dig chosen is larger than x (from k) and (j == 1) means it's smaller already i.e.
                    previously we encountered a smaller element */
                    if (dig > x && j == 0) break;
                    int sum = (i+dig) % d;
                    int smallerAlready = (j == 1) || (dig < x);
                    newDP[sum][smallerAlready] = (newDP[sum][smallerAlready] + DP[i][j]) % MOD;
                }
            }
        }
        DP = newDP;
    }
    cout << (DP[0][false] + DP[0][true] - 1 + MOD)%MOD << '\n';
    return 0;
}
