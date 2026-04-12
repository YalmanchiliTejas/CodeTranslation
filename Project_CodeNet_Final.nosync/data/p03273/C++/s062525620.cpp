#include <bits/stdc++.h>
using namespace std;

void del_blank_column(vector<string> &board, int H, int W) {
    vector<bool> check(W, false);
    for (int i = 0; i < W; i++) {
        int count = 0;
        for (int j = 0; j < H; j++) {
            if (board.at(j).at(i) == '#') {
                break;
            }
            else {
                count++;
            }
            if (count == H) {
                check.at(i) = true;
            }
        }
    }
    for (int i = W - 1; i >= 0; i--) {
        if (check.at(i)) {
            for (int j = 0; j < H; j++) {
                board.at(j).erase(i,1);
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> board(H);
    string blank = "";
    for (int i = 0; i < W; i++) blank += ".";
    for (int i = 0; i < H; i++) cin >> board.at(i);
    for (int i = H - 1; i >= 0; i--) {
        if (board.at(i) == blank) {
            board.erase(board.begin() + i);
        }
    }
    del_blank_column(board, board.size(), W);
    for (int i = 0; i < board.size(); i++) cout << board.at(i) << endl;
}
