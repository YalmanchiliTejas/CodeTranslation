#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;


bool solve(){
    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    for(int i=0;i<H;i++){
        cin >> field[i];
    }

    int x = 0, y = 0;
    while(true){
        if(field[y][x] != '#') return false;
        field[y][x] = '.';
        if(x == W-1 && y == H-1) break;
        char right = (x+1 < W) ? field[y][x+1] : '.';
        char down = (y+1 < H) ? field[y+1][x] : '.';
        if(right == '#' && down == '.'){
            x++;
        }else if(right == '.' && down == '#'){
            y++;
        }else{
            return false;
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(field[i][j] == '#') return false;
        }
    }
    return true;
}

int main(){
    if(solve()) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}