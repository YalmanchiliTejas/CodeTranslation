#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H);
    for (int i = 0; i < H; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < W; j++) {
            A.at(i).push_back(x.at(j));
        }
    }
    int w_count, h_count = 0;
    unordered_map<int, bool> rem_r, rem_c;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
//            cout << A.at(i).at(j);
            if (A.at(i).at(j) == '.') {
                w_count++;
            }
        }
        if (w_count == W) {
            rem_r[i] = true;
        }
        w_count = 0;
    }

    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (A.at(i).at(j) == '.') {
                h_count++;
            }
        }
        if (h_count == H) {
            rem_c[j] = true;
        }
        h_count = 0;
    }

    vector<vector<char>> ans(H - rem_r.size());
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (rem_c.find(j) == rem_c.end() && rem_r.find(i) == rem_r.end()) {
                cout << A.at(i).at(j);
            }
        }
        if (rem_r.find(i) == rem_r.end()) {
            cout << endl;
        }
    }

}