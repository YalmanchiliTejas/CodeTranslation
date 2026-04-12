#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount


int main() {
    int H, W;
    cin >> H >> W;
    vector<char> grid[10];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            grid[i].push_back(c);
        }
    }

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(grid[i][j]=='#')
                cnt++;
        }
    }

    if(cnt==H+W-1)
        puts("Possible");
    else{
        puts("Impossible");
    }

    return 0;
}