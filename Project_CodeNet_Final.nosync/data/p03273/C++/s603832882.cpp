#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int H, W;
char grid[100][100];
bool vert[100], side[100];

int main(){

    cin >> H >> W;
    rep(i, H)rep(j, W){
        cin >> grid[i][j];
        if(grid[i][j] == '#'){
            vert[i] = true;
            side[j] = true;
        }
    }

    rep(i, H)if(vert[i]){
        rep(j, W)if(side[j])cout << grid[i][j];
        cout << endl;
    }

}