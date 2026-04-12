#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define REP(i, n) FOR(i,0,n)

using namespace std;
typedef long long ll;
const int INF = 1e9;
int h,w;
char board[8][8];

bool check(){
    REP(i,h){
        REP(j,w){
            if(board[i][j]=='#'){
                if(i==0){
                    if(j==0){
                        if(board[i+1][j]==board[i][j+1]) return false;
                    }
                    else {
                        if(board[i][j-1]!='#') return false;
                        if(j==w-1){
                            if(board[i+1][j]=='#') continue;
                            else return false;
                        }
                        if(board[i+1][j]==board[i][j+1]) return false;
                    }
                }
                else if(i!=h-1){
                    if(j==0){
                        if(board[i-1][j]!='#') return false;
                        if(board[i][j+1]==board[i+1][j]) return false;
                        continue;
                    }
                    if(board[i-1][j]==board[i][j-1]) return false;
                    if(j==w-1){
                        if(board[i+1][j]!='#') return false;
                        continue;
                    }
                    if(board[i+1][j]==board[i][j+1]) return false;
                }
                else {
                    if(j==w-1) return true;
                    if(j==0){
                        if(board[i-1][j]!=board[i][j+1]) return false;
                        else continue;
                    }
                    if(board[i-1][j]==board[i][j-1]) return false;
                    if(board[i][j+1]!='#') return false;
                }
            }
        }
    }
}

void solve(){
    if(check()) cout << "Possible\n";
    else cout << "Impossible\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    REP(i,h){
        REP(j,w){
            cin >> board[i][j];
        }
    }
    solve();
    return 0;
}