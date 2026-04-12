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
#include <cassert>

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
using uInt = long long unsigned int;
using Double = long double;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Solve {
public:

    vector<vector<char>> decode(string s) {
        vector<vector<char>> ret(1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '/') {
                ret.push_back(vector<char>());
            } else if (s[i] == 'b') {
                ret.back().push_back('b');
            } else {
                rep(j, '0', s[i]) {
                    ret.back().push_back('.');
                }
            }
        }
        return ret;
    }

    string encode(vector<vector<char>> vv) {
        string ret;
        for (int i = 0; i < vv.size(); ++i) {
            for (int j = 0; j < vv[i].size(); ++j) {
                if (vv[i][j] == 'b') {
                    ret.push_back('b');
                } else {
                    if (!ret.size() || ret.back() == 'b' || ret.back() == '/') {
                        ret.push_back('1');
                    } else {
                        ret.back()++;
                    }
                }
            }
            if (i + 1 < vv.size()) {
                ret += '/';
            }
        }
        return ret;
    }

    bool solve() {
        string s;
        cin >> s;
        if (s == "#") return false;
        Int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        auto tapu = decode(s);
        tapu[a][b] = '.';
        tapu[c][d] = 'b';
        string tapi = encode(tapu);
        cout << tapi << endl;

        return true;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    while (Solve().solve());


    return 0;
}

