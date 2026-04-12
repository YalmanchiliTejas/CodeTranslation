#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <cassert>
#include <set>
#include <map>
#include <bitset>
#include <unordered_set>
#include <string>
#include <cstring>
#include <cmath>

#define forn(x, a)             for (int x = 0; x < a; x++)
#define fore(x, a, b, c)       for (int x = a; x <= b; x += c)
#define forr(x, a)             for (int x = a; x >= 0; x--)
#define all(container)         (container).begin(), (container).end()
#define rall(container)        (container).rbegin(), (container).rend()
#define sz(container)          (int) container.size()
#define mp                     make_pair
#define fi                     first
#define se                     second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector< vector< int > > vvi;
typedef vector<bool> vb;
typedef vector<long long> vll;

#ifdef LOCAL_DEFINE
    #include "../../library/debug.hpp"
#else
    #define debug(...) 0
#endif

void read(int &a) {scanf("%d", &a);}
void read(ll &a) {scanf("%lld", &a);}
void read(char* a, string& s) {scanf("%s", a); s = string(a);}
void read(float &a) {scanf("%f", &a);}
void read(double &a) {scanf("%lf", &a);}
void print(vi &a) {for (auto& x: a) printf("%d ", x); puts("");}
void print(int &a) {printf("%d ", a);}
void println(int &a) {printf("%d\n", a);}

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
int h, w;
char line[10];
vector<string> field;

void solve() {
    read(h), read(w);
    field.resize(h);
    forn(i, h) read(line, field[i]);
    vector<vb> visited(h, vb(w, false));
    int cnt = 0;
    forn(i, h) forn(j, w) if (field[i][j] == '.') ++cnt;
    debug(cnt);
    if (cnt == h * w) puts("Possible");
    else if (field[0][0] != '#') puts("Impossible");
    else {
        pii pos = mp(0, 0);
        bool ok = true;
        while(1) {
            visited[pos.fi][pos.se] = true;
            if (pos.fi == h - 1 && pos.se == w - 1) break;
            if (pos.fi + 1 < h && field[pos.fi + 1][pos.se] == '#' && pos.se + 1 < w && field[pos.fi][pos.se + 1] == '#') {
                ok = false;
                break;
            }
            if (pos.fi + 1 < h && field[pos.fi + 1][pos.se] == '#') ++pos.fi;
            else if (pos.se + 1 < w && field[pos.fi][pos.se + 1] == '#') ++pos.se;
            else {
                ok = false;
                break;
            }
        }
        if (!ok) puts("Impossible");
        else {
            forn(i, h) forn(j, w) if (field[i][j] == '#' && !visited[i][j]) {
                puts("Impossible");
                return;
            }
            puts("Possible");
        }
    }
}

int main(void) {
    int T = 1;
    while (T--)
        solve();
    return 0;
}