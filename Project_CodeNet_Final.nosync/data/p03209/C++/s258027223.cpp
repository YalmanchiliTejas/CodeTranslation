#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

// hamko utils
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
class ScopedTime {
public:
    ScopedTime(const std::string& msg = "") : msg_(msg) {
        start_ = std::chrono::system_clock::now();
    }
    void lap(const std::string& msg) {
        const auto duration_time = std::chrono::system_clock::now() - start_;
        const auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration_time);
        std::cerr << "[" << duration_ms.count() << " ms] " << msg << std::endl;
    }
    virtual ~ScopedTime() {
        this->lap(msg_);
    }
private:
    std::chrono::system_clock::time_point start_;
    std::string msg_;
};

size_t g_random_seed;
struct init_{ init_(){ std::ios::sync_with_stdio(false); std::cin.tie(0); srand(static_cast<unsigned int>(time(NULL))); g_random_seed = RAND_MAX / 2 + rand() / 2; } } init__;
namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = g_random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class

#define ldout fixed << setprecision(40) 
#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)
// end of hamko utils

vector<ll> num_of_burgers, num_of_patie;

ll func(ll n, ll x) {
    if (n == 0) {
        if (x <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (x <= 1 + num_of_burgers[n-1]) {
        return func(n-1, x-1);
    } else {
        return num_of_patie[n-1] + 1 + func(n-1, x-2-num_of_burgers[n-1]);
    }
}

int main(void) {
    ll N, X;
    cin >> N >> X;
    num_of_burgers.resize(N+1), num_of_patie.resize(N+1);
    for (int i = 0; i < N+1; i++) {
        num_of_burgers[i] = std::pow(2, i+2) - 3;
        num_of_patie[i] = std::pow(2, i+1) - 1;
        // std::cerr << "l: " << i << std::endl;
        // std::cerr << "num_of_burgers: " << num_of_burgers[i] << std::endl;
        // std::cerr << "num_of_patie: " << num_of_patie[i] << std::endl;
    }

    // ll sum_of_p = 0;
    // ll count_sum = 0;
    // std::cerr << "---------------" << std::endl;
    // while (true) {
    //     int l = 0;

    //     for (; l <= N+1; l++) {
    //         if (num_of_burgers[l] > X + (count_sum == 0 ? N - l : 0)) {
    //             std::cerr << "  exit at: " << l << std::endl;
    //             break;
    //         }
    //     }
    //     if (X == 1) {
    //         std::cout << sum_of_p << std::endl;
    //         return 0;
    //     }
    //     if (!(count_sum == 0 && X <= N - l)) {
    //         sum_of_p += num_of_patie[l-1];
    //     }
    //     count_sum++;

    //     std::cerr << "  sum_of_p " << sum_of_p<< std::endl;
    //     std::cerr << "  X: " << X  << std::endl;
    //     std::cerr << "  nb[l-1]: " << num_of_burgers[l-1] << std::endl;
    //     std::cerr << "     count_sum: " << count_sum<< std::endl;
    //     std::cerr << "--- "  << std::endl;
    //     /*
    //      *if (X >= num_of_burgers[l-1]
    //      *       && X <= num_of_burgers[l-1]+2) {
    //      *    if (X == num_of_burgers[l-1] + 2) {
    //      *        sum_of_p += 1;
    //      *    }
    //      *    std::cerr << "  break!" << std::endl;
    //      *    break;
    //      */
    //     if (X >= num_of_burgers[l-1] + (count_sum == 0 ? N - l : 0)
    //            && X <= num_of_burgers[l-1]+2+ (count_sum == 0 ? N - l : 0)) {
    //         if (X == num_of_burgers[l-1] + 2+ (count_sum == 0 ? N - l : 0)) {
    //             sum_of_p += 1;
    //         }
    //         std::cerr << "  break!" << std::endl;
    //         break;
    //     } else {
    //         X -= (num_of_burgers[l-1] + 2);
    //         sum_of_p += 1;
    //     }
    // }
    std::cout << func(N, X) << std::endl;

    return 0;
}
