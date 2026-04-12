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
using ll = int64_t;
using ull = uint64_t;

constexpr ll INF = 1000000000;/* 1e+9a */
namespace utils{

    class Repeater{
        int st;
        int ed;
        int d;
    public:
        class rep_iterator{
            int i; int d;
        public:
            rep_iterator(int x, int pd) :i(x), d(pd) {}

            int& operator*(){ return i; }
            bool operator==(const rep_iterator& k) const { return i == k.i; }
            bool operator!=(const rep_iterator& k) const { return i != k.i; }
            rep_iterator& operator++(){ i+=d; return *this; }
        };

        explicit Repeater(int N) :st(0), ed(N), d(1) {}
        Repeater(int b, int e) :st(b), ed(e), d(1) {if(st > ed){ st--; ed--; d = -1; } }

        rep_iterator begin() const{ return rep_iterator(st, d); }
        rep_iterator end() const{ return rep_iterator(ed, d); }

    };

    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool min_update(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool max_update(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }
#define ALL(x) begin(x), end(x)
#define rALL(x) rbegin(x), rend(x)
}
using namespace utils;


namespace xelmh_RCR {
    class RCR {
        // Residue Class Ring
    public:
        static const int64_t MOD = 1000000007;
//        static const int64_t MOD = 998244353;
        int64_t val;
        RCR(uint l) : val{l % MOD} {}
        RCR() : val{-1} {}

        bool is_nil(){
            return val == -1;
        }

        RCR pow(RCR m) const {
            RCR rv{1};
            auto nmul = val;
            while (m.val > 0) {
                if ((m.val & 1) == 1) {
                    rv.val *= nmul;
                    rv.val %= MOD;
                }
                nmul *= nmul;
                nmul %= MOD;
                m.val /= 2;
            }
            return rv;
        }
        RCR inv() const { /* return Inverse */ return this->pow(MOD - 2); }
        void operator+=(const RCR &a) {
            val += a.val;
            val %= MOD;
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
    };

    // supported operator :: + - * / ^
    RCR operator+(const RCR &a, const RCR &b) { return (a.val + b.val) % RCR::MOD; }
    RCR operator-(const RCR &a, const RCR &b) { return (a.val - b.val + RCR::MOD) % RCR::MOD; }
    RCR operator*(const RCR &a, const RCR &b) { return (a.val * b.val) % RCR::MOD; }
    RCR operator/(const RCR &a, const RCR &b) { return (a.val * b.inv().val) % RCR::MOD; }
    RCR operator^(const RCR &a, const RCR &b) { return a.pow(b); }

    bool operator==(const RCR &a, const RCR &b) { return a.val == b.val; }
    bool operator!=(const RCR &a, const RCR &b) { return a.val != b.val; }
    // IO
    std::ostream &operator<<(std::ostream &os, const RCR &m) { return os << m.val; }
    std::istream &operator>>(std::istream &is, RCR &m) { return is >> m.val; }

    RCR fact(ll N) {
        /* N -> N! */
        static vector<RCR> cal(1, RCR{1});

        if (cal.size() > N) return cal[N];
        else {
            RCR nm = fact(N - 1);
            assert(cal.size() == N);
            cal.push_back(nm * N);
            return cal[N];
        }
    }

    RCR choice(ll N, ll k) {
        /* N, k -> N C k */

        // N! / k!(N-k!)
        RCR ans = fact(N) / (fact(k) * fact(N - k));
        return ans;
    }
}
using namespace xelmh_RCR;


vector<vector<RCR>> dp;

RCR solve(const string& S, const int & D, int i = 0, int d = 0, bool ok = false){
    while(d < 0) d += D;
    if(i >= S.size())
        return d == 0;
    if(ok){
        if(!dp[i][d].is_nil()) return dp[i][d];
        else{
            dp[i][d] = 0;
            for (int j = 0; j < 10; ++j) {
                dp[i][d] += solve(S, D, i+1, d-j, true);
            } // end j
            return dp[i][d];
        }
    }
    else{
        RCR ret = 0;
        for (int j = 0; j < S[i] - '0'; ++j) {
            ret += solve(S, D, i+1, d-j, true);
        } // end j
        return ret + solve(S, D, i+1, d-S[i] + '0', false);
    }
}

void sub_main(istream &is) {
    string K;
    ll D;
    is >> K >>  D;
    if(!is) return;

    dp.clear();
    dp.resize(K.size(), vector<RCR>(D));
    RCR sum = solve(K, D);

    cout << sum - 1 << endl;

}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    string test_cases = "test_S.txt";
    cerr << "DEBUG MODE" <<  endl;
    cerr << test_cases << " -->" << endl;
    auto fs = fstream(test_cases, fstream::in);
    int lp = 0;
    while(fs) {
        lp++;
        cout << lp <<  "#------\n";
        sub_main(fs);
    }
    cout << "------#" << endl;
    if(lp <= 1) sub_main(cin);
#else
    sub_main(cin);
#endif
    return 0;
}
