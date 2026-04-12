#include <bits/stdc++.h>
//#include <boost/range/algorithm/find_if.hpp>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> board(H, vector<char>(W));
    vector<bool> hb(H, false);
    vector<bool> wb(W, false);
    rep(i, H){
        rep(j, W){
            cin >> board[i][j];
            if(board[i][j] == '#'){
                hb[i] = true;
                wb[j] = true;
            }
        }
    }
    rep(i, H){
        if(hb[i] == true){
            rep(j, W){
                if(wb[j] == true){
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
    }
	return 0;
}
