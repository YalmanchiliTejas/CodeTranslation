#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    rep(i,H) {
        rep(j,W) {
            cin >> A.at(i).at(j);
        }
    }
    rep(i,H) {
        rep(j,W) {
            if ((i != 0 || j != 0 || i != H - 1 || j != W - 1)) {
                if (A.at(i).at(j) == '#') {
                    if ((i - 1 >= 0 && j - 1 >= 0 && A.at(i - 1).at(j) == A.at(i).at(j - 1))
                    || (i - 1 < 0 && j - 1 >= 0 && A.at(i).at(j - 1) == '.')
                    || (i - 1 >= 0 && j - 1 < 0 && A.at(i - 1).at(j) == '.')
                    || (i + 1 < H && j + 1 < W && A.at(i + 1).at(j) == A.at(i).at(j + 1))
                    || (i + 1 >= H && j + 1 < W && A.at(i).at(j + 1) == '.')
                    || (i + 1 < H && j + 1 >= W && A.at(i + 1).at(j) == '.')) {
                        cout << "Impossible" << endl;
                        return  0;
                    }
                }
            }
        }
    }
    cout << "Possible" << endl;
}
