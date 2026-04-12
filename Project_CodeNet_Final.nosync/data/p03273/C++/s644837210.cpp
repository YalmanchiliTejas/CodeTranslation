#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

int main() {

    int H, W; cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    vector<string> temp;
    for (int i = 0; i < H; ++i) {
        bool line = true;
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != '.') {
                line = false;
            }
        }

        if (!line) {
            temp.push_back(S[i]);
        }
    }

    vector<string> ans(temp.size());
    for (int j = 0; j < W; ++j) {
        bool line = true;
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i][j] != '.') {
                line = false;
            }
        }

        if (!line) {
            for (int i = 0; i < temp.size(); ++i) {
                ans[i].push_back(temp[i][j]);
            }
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}