#include "bits/stdc++.h"

#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
using ull = unsigned long long;
using ll = long long;

struct __INIT {
    __INIT() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __init;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> G[i][j];
    }
    bool flag = true;
    for(int i = 0; i < H - 1; i++){
        for(int j = 0; j < W - 1; j++){
            if(G[i][j + 1] == '#' and G[i + 1][j] == '#' and G[i + 1][j + 1] == '#'){
                flag = false;
            }
            if(G[i][j] == '#' and G[i][j + 1] == '#' and G[i + 1][j] == '#'){
                flag = false;
            }
        }
    }
    if(flag) puts("Possible");
    else puts("Impossible");
}