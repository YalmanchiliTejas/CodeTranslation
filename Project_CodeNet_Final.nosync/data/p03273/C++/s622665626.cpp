#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    char a[h][w];
    int black_h[h] = {0};
    int black_w[w] = {0};
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        if(a[i][j] == '#'){
            black_h[i] = 1;
            black_w[j] = 1;
        }
    }

    rep(i, h){
        rep(j, w){
            if(black_h[i] + black_w[j] != 2) continue;
            else cout << a[i][j];
        }
        if(black_h[i] == 1) cout << endl;
    }


}