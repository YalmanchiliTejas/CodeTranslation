#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string expr;

vector<vector<int>> decode(string e) {
    int L = e.size();
    int width = 0, idx = 0;
    while (idx < L && e[idx] != '/') {
        if (e[idx] == 'b') width += 1;
        else width += e[idx] - '0';
        ++idx;
    }
    int height = 1;
    for (char ch : e) if (ch == '/') ++height;

    vector<vector<int>> res(height, vector<int>(width, 0));

    int row = 0, column = 0;
    for (char ch : e) {
        if (ch == '/') {
            row++;
            column = 0; 
        } else if (ch == 'b') {
            res[row][column++] = 1;
        } else {
            column += ch - '0';
        }
    }

    return res;
}

string encode(vector<vector<int>> b) {
    int height = b.size();
    int width = b[0].size();
    string res = "";
    for (int i = 0; i < height; ++i) {
        if (i > 0) res += "/";
        int count = 0;
        for (int j = 0; j < width; ++j) {
            if (b[i][j] == 1) {
                if (count > 0) res += string(1, count + '0');
                count = 0;
                res += "b";
            } else {
                ++count;
            }
        }
        if (count > 0) res += string(1, count + '0');
    }

    return res;
}

int main(void) {
    while (true) {
        cin >> expr;
        if (expr == "#") break;
        vector<vector<int>> board = decode(expr);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        board[a][b] = 0;
        board[c][d] = 1;
        cout << encode(board) << endl;
    }
    return 0;
}

