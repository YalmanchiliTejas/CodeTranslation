#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i, n) for (int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int         // 10^18
#define INF 1000000001           // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//---------------------------

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    
    int h,w;vector<string> board;cin>>h>>w;
    REP(i,h){
        string s;cin>>s;
        board.push_back(s);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]=='#'){
                if(i+1 >=h)continue;
                if(j+1 >=w)continue;
                if(board[i+1][j]=='.' && board[i][j+1]=='.'){
                    P("Impossible");
                    return 0;
                }
                if(board[i+1][j]=='#' && board[i][j+1]=='#'){
                    P("Impossible");
                    return 0;
                }
            }
        }
    }
    // 逆順に走査
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]=='#'){
                if(i-1 < 0)continue;
                if(j-1 < 0)continue;
                if(board[i-1][j]=='.' && board[i][j-1]=='.'){
                    P("Impossible");
                    return 0;
                }
                if(board[i-1][j]=='#' && board[i][j-1]=='#'){
                    P("Impossible");
                    return 0;
                }
            }
        }
    }
    P("Possible");
    return 0;
}