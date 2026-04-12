#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W; cin >> H >> W;
    string s[H];
    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
    }

    vector<bool> r(H, false), l(W, false);
    for (int i = 0; i < H; i++)
    {
        bool a = true;
        for (int j = 0; j < W; j++)
        {
            if(s[i][j] == '#') {
                a = false;
                break;
            }
        }
        r[i] = a;
    }

    for (int i = 0; i < W; i++)
    {
        bool a = true;
        for (int j = 0; j < H; j++)
        {
            if(s[j][i] == '#') {
                a = false;
                break;
            }
        }
        l[i] = a;
    }

    for (int i = 0; i < H; i++)
    {
        if(r[i]) continue;
        for (int j = 0; j < W; j++)
        {
            if(j == W - 1) {
                if(l[j]) cout << endl;
                else {
                    cout << s[i][j] << endl;
                }
            }
            else if(!l[j])cout << s[i][j];
        }
    }

    return 0;
}