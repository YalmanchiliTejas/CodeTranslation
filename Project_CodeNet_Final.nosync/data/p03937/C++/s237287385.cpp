#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;
    string S[H]; rep(i, H) cin >> S[i];
    int x = 0, y = 0;
    bool visited[H][W]; rep(i, H) rep(j, W) visited[i][j] = false;

    while(x < H && y < W){
        visited[x][y] = true;
        bool move = false;
        if(x+1 < H && S[x+1][y] == '#'){
            move = true;
            x++;
        }
        else if(y+1 < W && S[x][y+1] == '#'){
            move = true;
            y++;
        }
        if(!move) break;
    }
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '#' && (!visited[i][j])){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}