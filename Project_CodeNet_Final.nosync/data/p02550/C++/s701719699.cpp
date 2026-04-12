#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>
#include <cmath>
#include <complex>
#include <algorithm>
#include <utility>
#include <regex>
#include <cstdint>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;

namespace utils{
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
    ///----- aliases
    using ll = long long int;
    using ull = unsigned long long;

    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> inline bool CHMIN(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> inline bool CHMAX(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }

    ///----- vector I/O
    template<class T>
    vector<T> VEC(size_t n, T t){
        return vector<T>(n, t);
    }

    template<class ...Ts>
    auto VEC(size_t n, Ts ... ts){
        return vector<decltype(VEC(ts...))>(n, VEC(ts...));
    }


    template<class T>
    istream& operator>>(istream& is, vector<T>& v){
        for (auto &&x : v) { is >> x; } return is;
    }

    template<class T>
    ostream& operator<<(ostream& os, const vector<T>& v){
        auto p = v.begin();
        assert(p != v.end());
        os << *p++;
        while(p != v.end()){
            os << ' ' << *p++;
        }
        return os ;
    }

    template<class T>
    ostream& operator<<(ostream& os, const vector<vector<T>>& v){
        auto p = v.begin();
        assert(p != v.end());
        os << *p++;
        while(p != v.end()){
            os << '\n' << *p++;
        }
        return os;
    }

    ///----- tuple I/O
    template <class S, class T>
    istream& operator>>(istream& is, tuple<S, T>& t){
        return is >> get<0>(t) >> get<1>(t);
    }

    template <class S, class T>
    istream& operator>>(istream& is, pair<S, T>& t){
        return is >> get<0>(t) >> get<1>(t);
    }

    template <class S, class T, class U>
    istream& operator>>(istream& is, tuple<S, T, U>& t){
        return is >> get<0>(t) >> get<1>(t) >> get<2>(t);
    }

    template <class S, class T>
    ostream& operator<<(ostream& os, const tuple<S, T>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t);
    }

    template <class S, class T>
    ostream& operator<<(ostream& os, const pair<S, T>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t);
    }

    template <class S, class T, class U>
    ostream& operator<<(ostream& os, const tuple<S, T, U>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t) << ' ' <<  get<2>(t);
    }

    ///----- constants
    constexpr ll INFLL   = 1'000'000'000'000'000'020ll;
    constexpr ll INF     = 1'000'000'009;
    constexpr double PI      = 3.14'159'265'358'979'323'846;
    constexpr double EPS     = 1e-12;
}
using namespace utils;


class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}

    ll N, X, M;

    bool input() {
        is >> N >> X >> M;
        return !!is;
    }

    ll next(ll a){
        return (a*a) % M;
    }

    void run();
};

void solver::run(){
    if(!input()) return;
    vector<ll> A, SA;
    unordered_map<ll, ll> rA;
    SA.push_back(0);
    int i = 0;
    ll n = X;
    while(rA.count(n) == 0){
        SA.push_back(SA.back() + n);
        A.push_back(n);
        rA[n] = i++;
        n = next(n);
    }
    if(SA.size() > N) {
        cout << SA[N] << endl;
        return;
    }
    if(n == 0){
        cout << SA.back() << endl;
        return ;
    }
    int t = rA[n];
    ll ans = SA[t];
    N -= t;
    int lp = rA.size() - t;
    ans += (N/lp) * (SA.back() - SA[t]);
    N %= lp;
    ans += SA[t+N] - SA[t];

    cout << ans << endl;


}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_e.txt";
    cerr << test_cases << " -->" << endl;
    auto fs = fstream(test_cases, fstream::in);
    int loop = 0;
    while(fs) {
        loop++;
        cout << '#' << loop << "#------\n";
        solver(fs, cout).run();
    }
    if(loop <= 1) {
        cout << "===" << endl;
        while(cin) solver(cin, cout).run();
    }
#else
    solver(cin, cout).run();
#endif
    return 0;
}
