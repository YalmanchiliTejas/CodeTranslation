#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> G[i][j];
    vector<bool> tate(H);
    vector<bool> yoko(W);
    for(int i = 0; i < H; i++){
        bool can = true;
        for(int j = 0; j < W; j++) if(G[i][j] ==  '#') can = false;
        tate[i] = can;
    }
    for(int j = 0; j < W; j++){
        bool can = true;
        for(int i = 0; i < H; i++) if(G[i][j] == '#') can = false;
        yoko[j] = can;
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(!tate[i] and !yoko[j]) cout << G[i][j];
        }
        if(!tate[i]) cout << endl;
    }

}
