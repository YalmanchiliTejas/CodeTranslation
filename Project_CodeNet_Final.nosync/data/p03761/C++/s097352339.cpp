#include <bits/stdc++.h>
using namespace std;

#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REP1(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREP1(i, x) for (int i = ((int)(x)); i > 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb(a) push_back(a)
#define debug(x) cerr << #x << ": " << x << '\n'
const int MOD = (int)1e9 + 7;
const int INF = 1145141919;
using ll = long long;
using ull = unsigned long long;
using i_i = pair<int, int>;
using l_l = pair<ll, ll>;
using d_d = pair<double, double>;
using vint = vector<int>;

int main() {
    int n;
    cin >> n;
    vint v(30, -1);
    REP(i, n) {
        string s;
        cin >> s;
        vint tv(30);
        for (auto &c : s) {
            tv[c - 'a']++;
        }
        REP(j, 30) {
            if (v[j] < 0)
                v[j] = tv[j];
            else
                v[j] = min(v[j], tv[j]);
        }
    }
    REP(i, v.size()) {
        REP(j, v[i]) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
}