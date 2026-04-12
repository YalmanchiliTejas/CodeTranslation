#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    int h,w; cin >> h >> w;
    int x = 0,y = 0;
    int count = 0;
    vector<vector<char>> v(h+1,vector<char>(w+1,'.'));

    rep(i,h){
        rep(j,w){
            char tmp; cin >> tmp;
            v[i][j] = tmp;
            if(tmp == '#') count ++;
        }
    }
    if(count > w+h -1){
        cout << "Impossible";
        return 0;
    }

    while(1){
        if(v[y][x+1] == '#') x ++;
        else if(v[y+1][x] == '#') y ++;
        else {
            cout << "Impossible";
            return 0;
        }
        if(y == h-1 && x == w-1) break;
    }

    cout << "Possible";
    return 0;
}
