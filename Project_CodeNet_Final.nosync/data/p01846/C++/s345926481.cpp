#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    while(cin >> S, S != "#") {
        vector<vector<int>> field(9, vector<int>(9));
        int H, W, h = 0, w = 0;
        for(int i = 0; i < S.size(); ++i) {
            char c = S[i];
            if(c == 'b') {
                field[h][w] = 1;
                w++;
            } else if(c == '/') {
                h++;
                H = h + 1;
                W = w;
                w = 0;
            } else {
                w += c - '0';
            }
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        field[a - 1][b - 1] = 0;
        field[c - 1][d - 1] = 1;
        int now = 0;
        for(int i = 0; i < H; ++i) {
            now = 0;
            for(int j = 0; j < W; ++j) {
                if(field[i][j]) {
                    if(now != 0) {
                        cout << now;
                        now = 0;
                    }
                    cout << 'b';
                } else {
                    now++;
                }
            }
            if(now != 0) {
                cout << now;
            }
            if(i != H - 1) {
                cout << '/';
            }
        }
        cout << endl;
    }
    return 0;
}
