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

constexpr ll INF = numeric_limits<ll>::max() / 4;
namespace utils{
    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool min_update(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool max_update(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }
    using V_Set = unordered_set<int>;
    using E_Set = unordered_map<int, V_Set>;

#define ALL(x) begin(x), end(x)
#define rALL(x) rbegin(x), rend(x)
}
using namespace utils;


void sub_main(istream &is) {
    ll N;
    is >> N;
    if(!is) return;
    vector<ll> A(N);
    for (auto &&a : A) {
        is >> a;
    } // end a
    vector<int> lscol;
    for (int i = 0; i < N; ++i) {
        auto p = upper_bound(ALL(lscol), A[i], greater<int>());
        if(p == lscol.end()){
            lscol.push_back(A[i]);
        }
        else{
            assert(*p < A[i]);
            *p = A[i];
        }
    } // end i
    cout << lscol.size() << endl;
}

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    string test_cases = "test_E.txt";
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
