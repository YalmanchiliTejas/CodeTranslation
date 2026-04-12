#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;
const long double PI = acos((long double)(-1));

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

void solve() {
    string s; cin >> s; if (s == "#") exit(0);
    vector<string> vs(10, string(10, '.'));
    s += '/';
    int h = 0;
    int w = 0;
    int H = 0;
    int W = 0;
    bool f = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            vs[h][w] = 'b';
            w++;
            if(!f) W++;
        }
        else if (s[i] == '/') {
            w = 0;
            H++;
            h++;
            f = true;
        }
        else {
            w += s[i] - '0';
            if (!f) W += (s[i] - '0');
        }
    }
    vs.resize(H); for (int i = 0; i < H; i++) vs[i].resize(W);
    //for (int i = 0; i < H; i++) cout << vs[i] << endl;
    int a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
    vs[a][b] = '.';
    vs[c][d] = 'b';
    string res;
    int cnt = 0;
    s.clear();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vs[i][j] == 'b') {
                if (cnt) s += ('0' + cnt);
                s += 'b';
                cnt = 0;
            }
            else cnt++;
        }
        if (cnt) s += ('0' + cnt);
        s += '/';
        cnt = 0;
    }
    s.pop_back();
    cout << s << "\n";
}
int main()
{
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int kkt = 89;
    while (kkt) {
        solve();
    }
    return 0;
}
