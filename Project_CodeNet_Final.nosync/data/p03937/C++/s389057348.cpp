#include <bits/stdc++.h>
using namespace std;

char m[9][9];
bool judge(int h, int w, int x, int y){
    if(m[1][1] == '.') return false;
    if(x == h && y == w){
        return true;
    }
    if(m[x+1][y] == '#'){
        return judge(h,w,x+1,y);
    }
    if(m[x][y+1] == '#'){
        return judge(h, w, x, y+1);
    }
    if(m[x][y+1] == '.' && m[x+1][y] == '.')return false;
}

void ans(int h, int w, int x, int y){
    if(x == h && y == w){
        m[x][y] = 'o'; 
    }
    if(m[x+1][y] == '#'){
        m[x][y] = 'o';
        ans(h, w, x+1, y);
    }
    if(m[x][y+1] == '#'){
        m[x][y] = 'o';
        ans(h, w, x, y+1);
    }
}

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> m[i][j];
        }
    }
    m[1][1] = 'o';
    ans(h, w, 1, 1);
    bool flag = false;
    for(int i = 1 ; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(m[i][j] == '#')flag = true;
        }
    }
    if(!flag)cout << "Possible";
    else cout << "Impossible";

}