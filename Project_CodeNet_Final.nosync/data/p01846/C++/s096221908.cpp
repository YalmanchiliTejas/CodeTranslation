#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1) {
        vector<vector<char>> field(15, vector<char>(15, '#'));
        string S;
        cin >> S;
        if (S == "#") break;
        int column = 1;
        int row = 1;
        for (int i = 0; i < S.length(); i++) {
            // cout << column << row << endl;
            if (S[i] == 'b') {
                field[column][row] = 'b';
                row++;
            } else if (S[i] == '/') {
                column++;
                row = 1;
            } else {
                int tmp = row;
                for (; row < (S[i] - '0') + tmp; row++) {
                    field[column][row] = '.';
                }
            }
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a, b, c, d;
        swap(field[a][b], field[c][d]);

        string jfen = "";
        for (int i = 1; i < field.size() - 1; i++) {
            int cnt = 0;
            for (int j = 1; j < field[i].size() - 1; j++) {
                if (field[i][j] == 'b')
                    jfen += "b";
                else if (field[i][j] == '#') {
                    if (field[i + 1][1] != '#') jfen += "/";
                    break;
                } else {
                    cnt++;
                    if (field[i][j + 1] != '.') {
                        jfen += to_string(cnt);
                        cnt = 0;
                    }
                }
            }
        }
        cout << jfen << endl;
    }
}
