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

    int N;
    vector<ll> A;
    bool input() {
        N = 0;
        is >> N;
        A.resize(N);
        is >> A;
        return !!is;
    }

    void run();
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_F.txt";
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


void solver::run(){
    if(!input()) return;
    int d = N % 2 ? 2 : 1;
    auto dp = VEC(N, d+1, -INFLL);


    for (int i = 0; i < N; ++i) {
        for (int dif = 0; dif <= d; ++dif) {
            if(i - 2 >= 0) {
                UPMAX(dp[i][dif], dp[i-2][dif] + A[i]);
                if(dif >= 1){
                    if(i-3 < 0) dp[i][dif] = A[i];
                    else UPMAX(dp[i][dif], dp[i-3][dif-1] + A[i]);
                    UPMAX(dp[i][dif], dp[i-1][dif-1]);
                }
                if(dif >= 2){
                    if(i-4 < 0) dp[i][dif] = A[i];
                    else UPMAX(dp[i][dif], dp[i-4][dif-2] + A[i]);
                    UPMAX(dp[i][dif], dp[i-2][dif-2]);
                }
                if(dif >= 3){
                    if(i-5 < 0) dp[i][dif] = A[i];
                    else UPMAX(dp[i][dif], dp[i-5][dif-3] + A[i]);
                    if(i >= 3)
                        UPMAX(dp[i][dif], dp[i-3][dif-3]);
                }
            }
            else {
                if(dif >= i) UPMAX(dp[i][dif], dif == i ? A[i] : 0);
            }
        } // end dif
    } // end i
//    os << dp << endl;

    ll ans = max({dp.back()[d], dp.back()[d-1]});
    if(N % 2) UPMAX(ans, max(dp[N-2][1],dp[N-2][0]));
    else UPMAX(ans, (dp[N-2][0]));
    os << ans << endl;

}
