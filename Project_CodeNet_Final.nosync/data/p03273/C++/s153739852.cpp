#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<char>>board(a, vector<char>(b));
    vector<vector<bool>>board2(a, vector<bool>(b));
    vector<int>row(b, 0);
    rep(i, 0, a){
        rep(j, 0, b){
            cin >> board[i][j];
            board2[i][j] = true;
            if(board[i][j]=='.'){
                row[j]++;
            }
        }
    }
    rep(i, 0, a){
        int count1 = 0;
        rep(j, 0, b){
            if(board[i][j]=='.'){
                count1++;
            }
            if(row[j] == a)board2[i][j] = false;
        }
        if(count1 == b){
            rep(j, 0, b){
                board2[i][j] = false;
            }
        }
    }
    rep(i, 0, a){
        rep(j, 0, b){
            if(board2[i][j]){
                cout << board[i][j];
            }
        }
        cout << endl;
    }
}