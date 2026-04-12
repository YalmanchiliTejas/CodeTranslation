#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class t> void vin(vector<t>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    string s;
    while (cin >> s and s != "#") {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        char board[10][10];
        fill(board[0], board[10], 'x');

        int ycur=0, xcur=0, tmp=0;
        rep(i, s.size()) {
            if (s[i] == '/') { ycur++, xcur=0, tmp=0; }
            else {
                if (s[i] == 'b') board[ycur][xcur++] = 'b', tmp++;
                else {
                    for (; xcur<(s[i]-'0')+tmp; ++xcur) {
                        board[ycur][xcur] = '.';
                    }
                    tmp += (s[i]-'0');
                }

            }
        }
        //
        // rep(y, 10) {
        //     if (board[y][0] == 'x') break;
        //     rep(x, 10) {
        //         if (board[y][x] == 'x') break;
        //         cout << board[y][x];
        //     }
        //     cout << endl;
        // }

        if (board[a][b] == 'b') {
            board[a][b] = '.';
            board[c][d] = 'b';
        }

        // rep(y, 10) {
        //     if (board[y][0] == 'x') break;
        //     rep(x, 10) {
        //         if (board[y][x] == 'x') break;
        //         cout << board[y][x];
        //     }
        //     cout << endl;
        // }

        string ans = "";

        rep(y, 10) {
            if (y and board[y][0] != 'x') ans += "/";
            else if (y and board[y][0] == 'x') break;
            int num=0;
            rep(x, 10) {
                if (board[y][x] == 'x') continue;
                if (board[y][x] == '.') num++;
                else if (board[y][x] == 'b') {
                    if (num>0) ans += to_string(num);
                    ans += "b";
                    num=0;
                }
            }
            if (num>0) ans += to_string(num);
        }
        cout << ans << endl;
    }
}

