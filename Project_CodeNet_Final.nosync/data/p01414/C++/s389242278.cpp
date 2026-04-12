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


using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<n;++i)
#define FOR(i, a, b) for(int i=a;i<b;++i)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=b-1;i>=a;--i)

#define all(x) begin(x),end(x)
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

// edit
int N;
vector<int> H, W;
//vector<vector<bool>> st(4, vector<bool>(4)); //can put kukei
bool st[4][4][4][4]; // (sh, sw) ~ (th, tw)を押せるかどうか
vector<string> C(4);
//string C[4];
vi dp(1 << 16, -1);

int conv(int h, int w) {
    return 4 * h + w;
}

void print_state(int n) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << (n >> (conv(i, j)) & 1);
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int rec(int mask) {
//    print_state(mask);
    if (mask == (1 << 16) - 1) {
        return 0;
    }

    int &ret = dp[mask];
    if (ret != -1) return ret;

    ret = INF;

    FOR(sh, 0, 4) {
        FOR(sw, 0, 4) {
            FOR(th, sh, 4) {
                FOR(tw, sw, 4) {
                    int nmask = mask;
                    set<char> set;
                    if (st[sh][sw][th][tw]) {
                        FOR(s, sh, th + 1) {
                            FOR(w, sw, tw + 1) {
                                if (!(mask >> conv(s, w) & 1)) {
                                    nmask |= 1 << (conv(s, w));
                                    set.insert(C[s][w]);
                                }
                            }
                        }
                    }
                    if (set.size() == 1 && nmask != mask) {
                        int tmp = rec(nmask) + 1;
                        chmin(ret, tmp);
                    }
                }
            }
        }
    }

    return ret;
}


void solve() {
    cin >> N;
    REP(i, N) {
        int h, w;
        cin >> h >> w;
        H.push_back(h);
        W.push_back(w);

    }

//    C.resize(4);
    REP(i, 4) {
        cin >> C[i];
    }
//    cout << C << endl;

    for (int sh = -3; sh <= 3; ++sh) {
        for (int sw = -3; sw <= 3; ++sw) {
//            if (sh == 2 && sw == 2) {
//                int ushi = 13;
//            }
            for (int i = 0; i < N; ++i) {
                int th = sh + H[i] - 1;
                int tw = sw + W[i] - 1;

                int sh2 = max(0, sh);
                int sw2 = max(0, sw);
                int th2 = min(th, 3);
                int tw2 = min(tw, 3);
                if (th2 < 0 || tw2 < 0) continue;

//                cout << make_pair(P(sh2, sw2), P(th2, tw2)) << endl;

                st[sh2][sw2][th2][tw2] = true;
            }
        }
    }

    int ans = rec(0);
    cout << ans << endl;


}


int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    solve();


    return 0;
}

