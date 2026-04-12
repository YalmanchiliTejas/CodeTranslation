#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int h, w;
char a[8][8];

bool dfs(int i, int j){
    if(i == h-1 && j == w-1) return true;
    if(i+1 < h && a[i+1][j] == '#' && dfs(i+1,j)) return true;
    if(j+1 < w && a[i][j+1] == '#' && dfs(i,j+1)) return true;
    return false;
}

int main(){
    cin >> h >> w;
    int c = 0;
    rep(i,h) {
        rep(j,w){
            cin >> a[i][j];
            if(a[i][j] == '#') c++;
        }
    }
    if(dfs(0,0) && c == h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}