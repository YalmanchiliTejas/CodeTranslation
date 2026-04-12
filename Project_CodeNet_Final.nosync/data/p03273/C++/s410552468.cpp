#include <bits/stdc++.h>

using namespace std;

bool checkRow(string *row) {
    for(int i = 0; i < (*row).length(); i++) {
        if((*row)[i] != '.') return false;
    }
    return true;
}

bool checkColumn(vector<string> *board, int col) {
    for(int i = 0; i < (*board).size(); i++) {
        if((*board)[i][col] != '.') return false;
    }
    return true;
}

void delCol(vector<string> *board, int col) {
    for(int i = 0; i < (*board).size(); i++) {
        ((*board)[i]).erase(col, 1);
    }
}

int main() {
    int h, w;

    scanf("%d %d", &h, &w);

    string buf;
    vector<string> board;
    for(int i = 0; i < h; i++) {
        cin >> buf;
        if(!checkRow(&buf)) {
            board.push_back(buf);
        }
        else {
            // fprintf(stderr, "debug print : del row = %d\n", i);	// 4debug
        }
    }

    for(int i = 0; i < board[0].length(); i++) {
        if(board[0][i] == '.' && checkColumn(&board, i)) {
            delCol(&board, i);
            // fprintf(stderr, "debug print : del col = %d\n", i);	// 4debug
            i--;
        }
    }

    for(int i = 0; i < board.size(); i++) {
        cout << board[i] << "\n";
    }

    return 0;
}