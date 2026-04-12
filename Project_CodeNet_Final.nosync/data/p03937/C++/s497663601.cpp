#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];

    int i = 0, j = 0;
    while(i < h && j < w){
        grid[i][j] = '.';
        if(j+1 < w && grid[i][j+1] == '#'){
            j++;
            continue;
        }
        if(i + 1 < h && grid[i+1][j] == '#'){
            i++;
            continue;
        }
        break;
    }
    if(i == h-1 && j == w-1){
        rep(s,h){
            rep(t,w){
                if(grid[s][t] == '#'){
                    puts("Impossible");
                    return 0;
                }
            }
        }
        puts("Possible");
    } else
        puts("Impossible");
}