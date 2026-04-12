#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<iomanip>
#include<set>
#include<numeric>
#include<sstream>
#include<random>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

int main() {
    int n; cin >> n;
    int table[26][n + 1]; rep(i, 26) rep(j, n + 1) table[i][j] = 0;
    rep(i, n) {
        string s; cin >> s;
        rep(j, s.size()) {
            table[s[j] - 'a'][i]++;
        }
    }
    rep(i, 26) {
        int mc = inf;
        rep(j, n) {
            mc = min(mc, table[i][j]);
        }
        table[i][n] = mc;
    }
    rep(i, 26) {
        while (table[i][n]) {
            cout << (char)(i + 'a');
            table[i][n]--;
        }
    }
    cout << endl;
}
