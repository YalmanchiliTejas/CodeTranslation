#define DEBUG 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LLINF = 1e16;
const int MOD = 1000000007;
const int MOD2 = 998244353;
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#if DEBUG
#define debug(...)\
    do {\
        std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
        debug_impl(__VA_ARGS__);\
        std::cerr << std::noboolalpha;\
    } while (false)
#else
#define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
    { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
os << "{";
    for (auto it = v.begin(); it != v.end(); it++)
        {os << (it != v.begin() ? "," : "") << *it;}
    return os << "}";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x >= 30) cout << "Yes" << endl;
    else{
        cout << "No" << endl;
    }

}