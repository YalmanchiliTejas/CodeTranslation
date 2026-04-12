#include<bits/stdc++.h>
using namespace std;

string a[8];
int h, w;

bool dfs(int x, int y){
    if(a[y][x] == '.')return false;
    a[y][x] = '.';
    if(x == w - 1 && y == h - 1)return true;
    if(x < w - 1 && y < h - 1 && a[y+1][x] == '#' && a[y][x+1] == '#')return false;
    if(x < w - 1 && a[y][x+1] == '#')return dfs(x+1, y);
    if(y < h - 1 && a[y+1][x] == '#')return dfs(x, y+1);
    return false;
}

int main(){
    cin >> h >> w;
    for(int i=0;i<h;++i){
        cin >> a[i];
    }

    bool flag = true;
    if(dfs(0, 0)){
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j){
                if(a[i][j] == '#'){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "Possible" : "Impossible") << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}
