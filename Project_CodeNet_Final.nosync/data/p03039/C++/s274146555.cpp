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

namespace xelmh_RCR {
    class RCR {
        // Residue Class Ring
        static constexpr ll NIL = -1;
        static constexpr int64_t MOD = 1'000'000'007;
//        static constexpr int64_t MOD = 998'244'353;

        ll val;
    public:
        RCR(ll x) : val(x >= 0 ? x % MOD : MOD - (-x) % MOD) {}
        RCR(signed x) : val(x >= 0 ? x % MOD : MOD - (-x) % MOD) {}
        RCR(ull x) : val(x % MOD) {}
        RCR(unsigned x) : val(x % MOD) {}
        RCR() : val{NIL} {}

        bool is_nil() { return val == NIL; }

        RCR pow(ll n) const {
            ll r = 1, a = val;
            while (n) {
                if (n & 1) {
                    r *= a;
                    r %= MOD;
                }
                a *= a;
                a %= MOD;
                n /= 2;
            }
            return {r};
        }
        RCR inv() const { /* return Inverse */ assert(val != 0);
            return this->pow(MOD - 2);
        }

        void operator+=(const RCR &a) {
            val += a.val;
            if (val >= MOD) val -= MOD;
        }
        void operator-=(const RCR &a) {
            val -= a.val;
            if (val < 0) val += MOD;
        }
        void operator*=(const RCR &a) {
            val *= a.val;
            val %= MOD;
        }
        void operator/=(const RCR &a) {
            val *= a.inv().val;
            val %= MOD;
        }

        RCR operator+(const RCR &x) const {
            ll v = val + x.val;
            return {v};
        }
        RCR operator-(const RCR &x) const {
            ll v = val - x.val;
            return {v};
        }
        RCR operator*(const RCR &x) const {
            ll v = val * x.val;
            return {v};
        }
        RCR operator/(const RCR &x) const {
            ll v = val * x.inv().val;
            return {v};
        }

        bool operator==(const RCR &x) const { return x.val == val; }
        bool operator!=(const RCR &x) const { return x.val != val; }

        friend istream &operator>>(istream &is, RCR &r) {
            ll tmp;
            is >> tmp;
            r = tmp;
            return is;
        }
        friend ostream &operator<<(ostream &os, const RCR &r) { return os << r.val; }
    };

    RCR fact(ll N) {
        /* N -> N! */
        static vector<RCR> cal(1, RCR{1});
        assert(N >= 0);

        if (cal.size() > N) return cal[N];
        else {
            RCR nm = fact(N - 1);
            assert(cal.size() == N);
            cal.push_back(nm * N);
            return cal.back();
        }
    }

    /* N, k -> N C k */
    RCR choose(ll N, ll k) {
        // N! / k!(N-k!)
        RCR ans = fact(N) / (fact(k) * fact(N - k));
        return ans;
    }

    RCR operator "" _mod(unsigned long long x) {
        return RCR{x};
    }
}
using namespace xelmh_RCR;


class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}
    ll N, M, K;

    bool input() {
        is >> N >> M >> K;
        return !!is;
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


void solver::run(){
    if(!input()) return;
    RCR n, m, k;
    n = N; m = M; k = K;

    RCR ans = 0;
    for (int xd = 1; xd < N; ++xd) {
        ans += m*m*(n-xd) * xd;
    } // end xd
    for (int yd = 1; yd < M; ++yd) {
        ans += n * n * (m - yd) * yd;
    } // end xd
    RCR cons = choose(N*M-2, K-2);
    ans *= cons;
    os << ans << endl;
}
