#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;

int main() {
  	cin.tie(0);
  	ios::sync_with_stdio(false);
  
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    vector<int> h(H), w(W);

    rep(i, H) rep(j, W) {
        cin >> grid[i][j];
        if (grid[i][j] == '#') h[i] = w[j] = 1;
    }

    rep(i, H) if (h[i]) {
        rep(j, W) if (w[j]) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
