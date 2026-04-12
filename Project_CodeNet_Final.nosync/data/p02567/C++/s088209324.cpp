#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
#include <atcoder/all>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int op(int i, int j) { return max(i, j); }
int e() { return -1; }
int v;
bool f(int x) { return x < v; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    atcoder::segtree<int, op, e> seg(a);

    for (int i = 0; i < q; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            a--;
            seg.set(a, b);
        } else if (t == 2) {
            a--;
            cout << seg.prod(a, b) << '\n';
        } else {
            a--;
            v = b;
            cout << seg.max_right<f>(a) + 1 << '\n';
        }
    }    
    return 0;
}
