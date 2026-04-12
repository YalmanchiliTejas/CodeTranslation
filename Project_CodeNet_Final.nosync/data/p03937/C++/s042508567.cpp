#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <climits>
#include <math.h>
#include <memory.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
using ll = long long;
int N, M;
int cnt = 0;
int ans = 0;
int i_index;
int tmp;
bool Rok = true;
bool Uok = true;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};
string board[64];
int main(){
    int H, W;
    cin >> H >> W;
    rep(i, H) cin >> board[i];
    rep(i, H) rep(j, W){
        if(board[i][j] == '#')
            cnt++;
    }
    if(cnt == H + W - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}