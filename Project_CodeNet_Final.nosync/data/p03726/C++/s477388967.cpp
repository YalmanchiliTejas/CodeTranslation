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
using ll = long long;
using ull = unsigned long long;

constexpr ll INF = 1'000'000'000'000'000'000;
namespace utils{
#define ALL(x) begin(x), end(x)
#define rALL(x) rbegin(x), rend(x)
    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool min_update(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool max_update(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }
    using V_Set = unordered_set<int>;
    using E_Set = unordered_map<int, V_Set>;

    ll operator"" _64(unsigned long long x){ return ll(x); }
    ull operator"" _64u(unsigned long long x){ return ull(x); }

    template<class T>
    vector<T> make_vector(int n, T t){
        return vector<T>(n, t);
    }
    template<class ...Ts>
    auto make_vector(int n, Ts ... ts){
        return vector<decltype(make_vector(ts...))>(n, make_vector(ts...));
    }

    template<class T>
    ostream& operator<<(ostream& os, const vector<T>& v){
        for (auto &&x : v) { os << x << ' '; } cout << endl; return os ;
    }
}
using namespace utils;

class solver{
    istream& is;
    ostream& os;
    E_Set E;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}

    bool dfs(int v, int p = -1){
        int c = 0;
        for (auto &&u : E[v]) {
            if(u == p) continue;
            c += dfs(u, v);
        } // end
        if(c >= 2) throw 1;

        return c != 1;
    }

    bool solve(){
        try{
            return dfs(1);
        }
        catch(int k){
            return true;
        }
    }

    void run(){
        ll N;
        is >> N;
        if(!is) return;
        for (int i = 0; i < N - 1; ++i) {
            int A, B; is >> A >> B;
            E[A].insert(B);
            E[B].insert(A);
        } // end i
        cout << (solve() ? "First" : "Second") << endl;

    }
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    string test_cases = "test_BlackAndWhiteTree.txt";
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
