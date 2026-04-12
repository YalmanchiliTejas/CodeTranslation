#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int H, W;
char a[110][110];

int main()
{
    cin >> H >> W;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> a[h][w];
        }
    }
    vector<int> bh, bw;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (a[h][w] == '#') {
                bh.push_back(h);
                break;
            }
        }
    }
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            if (a[h][w] == '#') {
                bw.push_back(w);
                break;
            }
        }
    }

    for (auto& eh: bh) {
        for (auto& ew : bw) {
            cout << a[eh][ew];
        }
        cout << endl;
    }
    return 0;
}