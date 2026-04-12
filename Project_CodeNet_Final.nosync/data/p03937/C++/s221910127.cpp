#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h,w;
    cin >> h >> w;
    
    vector<vector<char>> board(h,vector<char>(w));
    
    rep(i,h){
        rep(j,w){
            cin >> board[i][j];
        }
    }
    int i = 0;
    int j = 0;

    bool flag = true;
    
    while(true){
        bool next = false;
        if(i + 1 < h){
            if(board[i+1][j] == '#'){
                board[i][j] = '.';
                next = true;
                i++;
            }
            
        }
        
        if(j + 1 < w){
            if(board[i][j+1] == '#'){
                board[i][j] = '.';
                j++;
                next = true;
            }
        }
        
        if(!next) break;
        
        if(i == h - 1 and j == w - 1) {
            board[i][j] = '.';
            break;
        }
    }
    
    rep(i,h){
        rep(j,w){
            if(board[i][j]=='#') flag = false;
        }
    }
    
    if(flag) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
}
