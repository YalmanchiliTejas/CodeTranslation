#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }
    bool h[H]={false}, w[W]={false};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                h[i] = w[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        bool check = false;
        for (int j = 0; j < W; j++) {
            if (h[i] && w[j]){
                cout << a[i][j];
                check = true;
            }
        }
        if (check) cout << endl;
    }
}