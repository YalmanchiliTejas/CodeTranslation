//=================================
// Created on: 2018/07/03 17:26:33
//=================================
// 7+9:52~
#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (string s;;) {
        cin >> s;
        if (s == "#") { break; }
        int H = 0, W = 0;
        vector<vector<bool>> ball(9, vector<bool>(9, false));
        for (int i = 0, w = 0; i < s.size(); i++) {
            if (s[i] == '/') {
                H++, W = w, w = 0;
            } else if (s[i] == 'b') {
                ball[H][w] = true, w++;
            } else {
                w += s[i] - '0';
            }
        }
        H++;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        ball[a][b] = false, ball[c][d] = true;
        string ans;
        for (int i = 0; i < H; i++) {
            int hole = 0;
            for (int j = 0; j < W; j++) {
                if (ball[i][j]) {
                    if (hole > 0) { ans += to_string(hole), hole = 0; }
                    ans.push_back('b');
                } else {
                    hole++;
                }
            }
            if (hole > 0) { ans += to_string(hole), hole = 0; }
            ans.push_back('/');
        }
        ans.pop_back();
        cout << ans << endl;
    }
    return 0;
}

