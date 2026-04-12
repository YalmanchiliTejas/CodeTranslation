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
    using i32 = int32_t;
    using u32 = uint32_t;
    using i64 = int64_t;
    using u64 = uint64_t;
    using ll = i64;
    using ull = u64;

    using f32 = float;
    using f64 = double;

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
    vector<T> VIN(istream& is, size_t n){
        vector<T> v(n);
        for (int i = 0; i < n; ++i) {
            is >> v[i];
        } // end i
        return v;
    }

    template<class T>
    auto VIN(istream& is, size_t n, size_t ts...){
        auto v = vector<decltype(VIN<T>(is, ts))>(n);
        for (auto &&x : v) {
            x = VIN<T>(is, ts);
        } // end x
        return v;
    }

    template<class T>
    bool VOUT(ostream& os, vector<T>& v){
        for (auto &&x : v) {
            os << x  << ' ';
        } // end x
        return !!os;
    }

    template<class T>
    bool VOUT(ostream& os, vector<vector<T>>& v, char endc = '\n'){
        for (auto &&vs : v) {
            VOUT(os, vs);
            os << endc;
        } // end vs
        return !!os;
    }

    ///----- tuple I/O
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

    ///----- constants
    constexpr i64 INFLL   = 1'000'000'000'000'000'020ll;
    constexpr i32 INF     = 1'000'000'009;
    constexpr f64 PI      = 3.14'159'265'358'979'323'846;
    constexpr f64 EPS     = 1e-12;
}
using namespace utils;

namespace xelm_ModInt {
    class ModInt {
        static constexpr ll NIL = -1;
        static constexpr int64_t MOD = 1'000'000'007;
//        static constexpr int64_t MOD = 998'244'353;

        ll val;
    public:
        ModInt(ll x) : val(x >= 0 ? x % MOD : MOD - (-x) % MOD) {}
        ModInt(signed x) : val(x >= 0 ? x % MOD : MOD - (-x) % MOD) {}
        ModInt(ull x) : val(x % MOD) {}
        ModInt(unsigned long long x) : val(x % MOD) {}
        ModInt() : val{NIL} {}

        bool is_nil() { return val == NIL; }

        ModInt pow(ll n) const {
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
        ModInt inv() const { /* return Inverse */ assert(val != 0);
            return this->pow(MOD - 2);
        }

        void operator+=(const ModInt &a) {
            val += a.val;
            if (val >= MOD) val -= MOD;
        }
        void operator-=(const ModInt &a) {
            val -= a.val;
            if (val < 0) val += MOD;
        }
        void operator*=(const ModInt &a) {
            val *= a.val;
            val %= MOD;
        }
        void operator/=(const ModInt &a) {
            val *= a.inv().val;
            val %= MOD;
        }

        ModInt operator+(const ModInt &x) const {
            ll v = val + x.val;
            return {v};
        }
        ModInt operator-(const ModInt &x) const {
            ll v = val - x.val;
            return {v};
        }
        ModInt operator*(const ModInt &x) const {
            ll v = val * x.val;
            return {v};
        }
        ModInt operator/(const ModInt &x) const {
            ll v = val * x.inv().val;
            return {v};
        }

        bool operator==(const ModInt &x) const { return x.val == val; }
        bool operator!=(const ModInt &x) const { return x.val != val; }

        friend istream &operator>>(istream &is, ModInt &r) {
            ll tmp;
            is >> tmp;
            r = tmp;
            return is;
        }
        friend ostream &operator<<(ostream &os, const ModInt &r) { return os << r.val; }
    };

    ModInt fact(ll N) {
        /* N -> N! */
        static vector<ModInt> cal(1, ModInt{1});
        assert(N >= 0);

        if (cal.size() > N) return cal[N];
        else {
            ModInt nm = fact(N - 1);
            assert(cal.size() == N);
            cal.push_back(nm * N);
            return cal.back();
        }
    }

    /* N, k -> N C k */
    ModInt choose(ll N, ll k) {
        // N! / k!(N-k!)
        ModInt ans = fact(N) / (fact(k) * fact(N - k));
        return ans;
    }

    ModInt operator "" _mod(unsigned long long x) {
        return ModInt{x};
    }
}
using namespace xelm_ModInt;


class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}

    bool input() {
        return !!is;
    }

    void run();
};


void solver::run(){
    if(!input()) return;
    int N;
    is >> N;
    auto A = VIN<ModInt>(is, N);
    auto SA = VEC(N+1, 0_mod);
    ModInt ans = 0;
    for (int i = 0; i < A.size(); ++i) {
       SA[i+1] = SA[i] + A[i];
    } // end i
    for (int i = 0; i < A.size(); ++i) {
        ans += A[i] * (SA.back() - SA[i+1]);
    } // end i
    cout << ans << endl;

}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_C.txt";
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
