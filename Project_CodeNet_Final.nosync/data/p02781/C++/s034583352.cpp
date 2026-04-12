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
using ll  = long long;
using ull = unsigned long long;

namespace utils{
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> inline bool UPMIN(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> inline bool UPMAX(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }

    template<class T>
    vector<T> VEC(int n, T t){
        return vector<T>(n, t);
    }
    template<class ...Ts>
    auto VEC(int n, Ts ... ts){
        return vector<decltype(VEC(ts...))>(n, VEC(ts...));
    }

    template <class S, class T>
    istream& operator>>(istream& is, tuple<S, T>& t){
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

    template <class S, class T, class U>
    ostream& operator<<(ostream& os, const tuple<S, T, U>& t){
        return os << get<0>(t) << ' ' <<  get<1>(t) << ' ' <<  get<2>(t);
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

    template<class ...Ts>
    ostream& operator<<(ostream& os, const vector<tuple<Ts...>>& v){
        auto p = v.begin();
        assert(p != v.end());
        os << *p++;
        while(p != v.end()){
            os << '\n' << *p++;
        }
        return os;
    }

    constexpr long long INFLL   = 1'000'000'000'000'000'000ll;
    constexpr int       INF     = 1'000'000'000;
    constexpr double    PI      = 3.14'159'265'358'973;
    constexpr double    EPS     = 1e-10;
}
using namespace utils;


class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}

    string N;
    int K;
    bool input() {
        is >> N;
        is >> K;
        return !!is;
    }

    decltype(VEC(N.size(), K, 2, 0ll)) dp;

    ll calc(const int i, const int k, const int less){
        if(k == 0) return 1;
        if(i < 0) return 0;
        if(dp[i][k][less] != 0)
            return dp[i][k][less];
        // case 0
        dp[i][k][less] += calc(i-1, k, less or N[i] > '0');
        for (auto j = 1; 10 > j; ++j) {
            if(less or N[i] >= '0' + j)
                dp[i][k][less] += calc(i-1, k-1, less or N[i] > '0' + j);
        } // end i
        return dp[i][k][less];
    }


    void run();
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_E.txt";
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


void solver::run() {
    if (!input()) return;
    dp = VEC(N.size(), K+1, 2, 0ll);
    reverse(ALL(N));
    calc(N.size()-1, K, 0);
    os << dp.back()[K][0] << endl;
}
