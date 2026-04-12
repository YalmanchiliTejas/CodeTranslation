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

constexpr ll INF = 100000000000000;/* 1e+9a */
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

class solver{
    vector<vector<ll>> dp;
    vector<ll> A;
public:
    solver(vector<ll> A) : dp(A.size(), vector<ll>(A.size(), INF)), A(A) {}

    ll solve(int l, int r){
       if(r < l) return 0;
       if(dp[l][r] != INF) return dp[l][r];

       return dp[l][r] = max(A[l] - solve(l+1, r), A[r] - solve(l, r-1));
    }

};


void sub_main(istream &is) {
    ll N;
    is >> N;
    if(!is) return;
    vector<ll> A(N);
    for (auto &&a : A) {
        is >> a;
    } // end a
    cout << solver(A).solve(0, N-1) << endl;

}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    string test_cases = "test_L.txt";
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
