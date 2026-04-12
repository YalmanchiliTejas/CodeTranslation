#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W + 1));

    vector<bool> ver(W, true), hor(H, true);
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> a[i][j];
            if(a[i][j] == '.') {
                ver[j] = ver[j] & true;
                hor[i] = hor[i] & true;
            } else
                ver[j] = hor[i] = false;
        }
    }

    for(int i = 0; i < H; ++i) {
        if(hor[i])
            continue;
        for(int j = 0; j < W; ++j) {
            if(ver[j])
                continue;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
