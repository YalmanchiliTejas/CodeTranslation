#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct info {
    ll val, to;
};

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    vector<vector<info>> doubling(60, vector<info>(m));
    for (ll i = 0; i < m; i++)doubling[0][i] = {i, i * i % m};

    for (int t = 1; t < 60; t++) {
        for (ll i = 0; i < m; i++) {
            ll mid = doubling[t - 1][i].to;
            doubling[t][i].val = doubling[t - 1][i].val + doubling[t - 1][mid].val;
            doubling[t][i].to = doubling[t - 1][mid].to;
        }
    }

    ll ret = 0;
    for (int i = 0; i < 60; i++) {
        if (n & (1LL << i)) {
            ret += doubling[i][x].val, x = doubling[i][x].to;
        }
    }

    cout << ret << endl;
    return 0;
}
