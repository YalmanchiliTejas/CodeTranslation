#include <bits/stdc++.h>
using namespace std;

int H, W; 
vector<string> A;
bool ans;

void dfs(int h, int w, vector<vector<bool>> reach){
    reach[h][w] = true;

    int dh[2] = {0,1};
    int dw[2] = {1,0};
    for(int i=0; i<2; i++){
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(0 <= nh && nh < H && 0 <= nw && nw < W && A[nh][nw] == '#'){
            dfs(nh,nw,reach);
        }
    }

    if(h == H-1 && w == W-1){
        for(int i=0; i<H; i++) for(int j=0; j<W; j++){
            if(!reach[i][j] && A[i][j] == '#') return;
        }
        ans = true;
    }
}

int main(){
    cin >> H >> W;
    A = vector<string>(H);
    for(int i=0; i<H; i++) cin >> A[i];

    vector<vector<bool>> reach;
    reach = vector<vector<bool>>(H, vector<bool>(W,false));
    reach[0][0] = true;

    ans = false;
    dfs(0,0,reach);

    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
