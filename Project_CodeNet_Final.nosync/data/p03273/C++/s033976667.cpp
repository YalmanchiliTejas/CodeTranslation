#include<bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    string s[H];
    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
    }

    int a[H][W];
    memset(a, 0, sizeof(a));

    for (int i = 0; i < H; i++)
    {
        bool b = true;
        for (int j = 0; j < W; j++)
        {
            if(s[i][j] == '#') b = false;
        }
        if(b){
            for (int j = 0; j < W; j++)
            {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < W; i++)
        {
            bool b = true;
            for (int j = 0; j < H; j++)
            {
                if(s[j][i] == '#') b = false;
            }
            if(b){
                for (int j = 0; j < H; j++)
                {
                    a[j][i] = 1;
                }
            }
        }

    int cnt;
    for (int i = 0; i < H; i++)
    {
        cnt = 10;
        for (int j = 0; j < W; j++)
        {
            cnt = min(a[i][j], cnt);
            if(a[i][j] == 0) {
                cout << s[i][j];
            }
        }
        if(cnt == 0) cout << endl;
    }
}