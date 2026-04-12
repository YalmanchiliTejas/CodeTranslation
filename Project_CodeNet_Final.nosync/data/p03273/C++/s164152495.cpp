#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i < H; i++) cin >> a[i];
    int dH[H], dW[W];
    for(int i = 0; i < H; i++) dH[i] = 0;
    for(int i = 0; i < W; i++) dW[i] = 0;

    for(int i = 0; i < H; i++) {
        bool allwhite = true;
        for(int j = 0; j < W; j++) {
            if(a[i][j] == '#') {
                allwhite = false;
                break;
            }
        }
        if(allwhite) dH[i] = 1;
    }

    for(int i = 0; i < W; i++) {
        bool allwhite = true;
        for(int j = 0; j < H; j++) {
            if(a[j][i] == '#') {
                allwhite = false;
                break;
            }
        }
        if(allwhite) dW[i] = 1;
    }

    for(int i = 0; i < H; i++) {
        bool flag = false;
        for(int j = 0; j < W; j++) {
            if(dH[i] == 0 && dW[j] == 0) {
                cout << a[i][j];
                flag = true;
            }
        }
        if(flag) cout << "\n";
    }
    return 0;
}
