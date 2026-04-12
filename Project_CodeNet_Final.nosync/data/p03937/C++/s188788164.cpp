#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

int H, W;
vector<string> S;
bool flag = false;

int dfs(int h, int w){
    //cout << h << " " << w << " " << flag << endl;
    S[h][w] = '.';
    if(flag) return 0;
    if(h == H-1 && w == W-1){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(S[i][j] == '#'){
                    flag = true;
                    break;
                    return 0;
                }
            }
        }
        return 0;
    }

    if(h+1 < H && w+1 < W){
        if(S[h][w+1] == S[h+1][w]){
            flag = true;
            return 0;
        }
        if(S[h+1][w] == '#') dfs(h+1, w);
        if(S[h][w+1] == '#') dfs(h, w+1);
    }

    else if(h == H-1 && w+1 < W){
        if(S[h][w+1] == '#') dfs(h, w+1);
        else { flag = true; return 0;}

    }
    else if(w == W-1 && h+1 < H){
        if(S[h+1][w] == '#') dfs(h+1, w);
        else { flag = true; return 0;}
    }
    return 0;

}


int main(){
    cin >> H >> W;
    S.resize(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    if(S[0][0] != '#' || S[H-1][W-1] != '#'){
        cout << "Impossible" << endl;
        return 0;
    }
    //cout << flag << endl;
    dfs(0, 0);
    //cout << flag << endl;
    if(flag) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
}
