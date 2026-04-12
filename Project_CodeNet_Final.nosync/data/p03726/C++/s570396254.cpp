#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:
    Int N;
    vector<vector<Int>> tree;

    int dfs(int v, int p = -1) {
        if (tree.size() == 1 && p != -1) return 1;
        int cnt = 0;
        for (auto e : tree[v]) {
            if (e != p) {
                int tmp = dfs(e, v);
                if (tmp == -1) return -1;
                if (tmp == 1) cnt++;
            }
        }
        if (cnt > 1) return -1;
        return !cnt;
    }

    void solve() {
        cin >> N;
        tree.resize(N);
        for (int i = 0; i + 1 < N; ++i) {
            Int a, b;
            cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int neri = dfs(0);
        if (neri == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }

//        vector<Int> dig1;
//        for (int i = 0; i < N; ++i) {
//            if (tree[i].size() == 1) dig1.push_back(i);
//        }
//
//        vector<Int> puni(N);
//        for (auto e : dig1) {
//            for (auto f : tree[e]) {
//                puni[f]++;
//            }
//        }
//        for (auto e : puni) {
//            if (e >= 2) {
//                cout << "First" << endl;
//                return;
//            }
//        }
//        cout << "Second" << endl;


    }


};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
