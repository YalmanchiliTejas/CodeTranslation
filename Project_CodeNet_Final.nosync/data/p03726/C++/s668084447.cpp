#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int MAXN = 1e5 + 1, RAME = 10;
const int dirx[4] = {0, 1, 0, -1}, diry[4] = {1, 0, -1, 0};


int n;
int len[MAXN];
vector <int> edge[MAXN];
set <pair <int, int>> que;

void erase(int i) {
    for (int j: edge[i]) {
        pair <int, int> v = {len[j], j};
        if (que.count(v)) {
            que.erase(v);
            --len[j];
            que.insert({len[j], j});
        }
    }
    que.erase({len[i], i});
}

int main() {
    //read(FILENAME);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for (int i = 0; i < n; ++i) {
        que.insert({edge[i].size(), i});
        len[i] = edge[i].size();
    }
    bool turn = true;
    while (que.size()) {
        auto v = *que.begin();
        if (v.x == 0 && turn) {
            cout << "First" << endl;
            return 0;
        }
        if (!turn) {
            erase(v.y);
        } else {
            for (int j: edge[v.y]) {
                if (que.count({len[j], j})) {
                    erase(j);
                    break;
                }
            }
        }
        turn ^= 1;
    }
    cout << "Second" << endl;
}