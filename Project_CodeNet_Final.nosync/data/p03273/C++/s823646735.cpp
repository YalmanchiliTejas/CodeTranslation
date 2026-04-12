#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int h,w;

string board[110];
bool goodx[110],goody[110];

int main() {
    cin >> h >> w;

    rep(i,h){
        cin >> board[i];
    }
    rep(i,h){
        rep(j,w){
            if(board[i][j]=='#'){
                goodx[i]=true;
                goody[j]=true;
            }
        }
    }
    rep(i,h){
        if(goodx[i]){
            rep(j,w){
                if(goody[j]) cout << board[i][j];
            }
        cout << endl;
        }
    }
}