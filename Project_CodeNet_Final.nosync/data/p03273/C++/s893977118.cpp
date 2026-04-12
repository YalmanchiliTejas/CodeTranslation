#include <bits/stdc++.h>
using namespace std;
int main() {
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    vector<bool> X(H,false);
    vector<bool> Y(W,false);
    for (int i = 0; i < H; i++) {
        cin >> a[i];
        for(int j = 0; j < W; j++) {
            if(a[i][j] == '#') {
                X[i] = true;
                Y[j] = true;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(X[i]) {
                if(Y[j]) {
                    cout << a[i][j];
                }
            }
        }
        cout << endl;
    }
}