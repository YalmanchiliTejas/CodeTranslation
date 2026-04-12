#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll h, w, sharp = 0;
    cin >> h >> w;
    char field[9][9];
    fill(field[0], field[9], '.');
    rep(i, h){
        rep(j, w){
            cin >> field[i][j];
            if(field[i][j] == '#') sharp++;
        }
    }
    ll x = 0, y = 0, cnt = 1;
    while(true){
        if(field[y+1][x] == '.' && field[y][x+1] == '.') break;
        else if(field[y][x+1] == '#') x++;
        else if(field[y+1][x] == '#') y++;
        cnt++;
    }
    if(cnt == sharp) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}