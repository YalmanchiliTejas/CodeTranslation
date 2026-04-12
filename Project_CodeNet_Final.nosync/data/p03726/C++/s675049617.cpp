// happy valentine's day with two code
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(int)(a);i--)
template<typename T> ostream& operator<<(ostream& s, vector<T> t) {rep(i, 0, t.size()) s << (i ? " " : "") << t[i]; return s;}
template<typename T> istream& operator>>(istream& s, vector<T> &t) {rep(i, 0, t.size()) s >> t[i]; return s;}
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> t) {s << "(" << t.first << "," << t.second << ")"; return s;}
template<typename T, typename U> istream& operator>>(istream& s, pair<T, U> &t) {s >> t.first >> t.second; return s;}
typedef long long ll;

const int N = 1e5 + 10;
vector<int> g[N];
bool win = false;
int bad = 0;

bool dfs(int a, int from) {
    int sons = 0;
    for (auto b : g[a]) {
        if (b == from) continue;
        bool ex = dfs(b, a);
        if (!ex) continue;
        sons++;
    }
    if (sons > 1) {
        win = true;
    }
    if (sons == 1) {
        bad += 2;
        return false;
    }
    return true; //leaf
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n == 2) {
        cout << "Second" << endl;
        return 0;
    }
    rep(i, 1, n + 1) {
        if (g[i].size() > 1) {
            dfs(i, -1);
            break;
        }
    }
    if (win || n - bad == 1) {
        cout << "First" << endl;
        return 0;
    }
    //cout << "b:" << bad << endl;
    assert(n == bad);
    cout << "Second" << endl;
}
