#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(h, H) cin >> a[h];
    vector<bool> allwhiteH(H, false);
    vector<bool> allwhiteW(W, false);
    rep(h, H) {
        int index = a[h].find("#");
        if (index == string::npos) {
            allwhiteH[h] = true;
        }
    }
    rep(w, W) {
        bool allwhiteflag = true;
        rep(h, H) {
            if (a[h][w] == '#') allwhiteflag = false;
        }
        if (allwhiteflag) allwhiteW[w] = true;
    }

    rep(h, H) {
        if (!allwhiteH[h]) {
            rep(w, W) {
                if (!allwhiteW[w]) {
                    cout << a[h][w];
                }
            }
            cout << endl;
        }
    }
}