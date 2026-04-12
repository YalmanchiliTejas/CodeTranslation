#include <bits/stdc++.h>
using namespace std;

int h,w;
vector<string> s;

bool solve();
bool isvalid(int x,int y){
    return x >= 0 && x < h && y >= 0 && y < w;
}

int main(){
    cin >> h >> w;
    s.resize(h);
    for(int i = 0;i < h;++i)cin >> s[i];
    if(solve())cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}

bool solve(){
    int cnt = 0,x = 0,y = 0,now = 1;
    for(int i = 0;i < h;++i)for(int j = 0;j < w;++j)cnt += s[i][j] == '#';
    while(x != h-1 || y != w-1){
        if(isvalid(x+1,y)&&isvalid(x,y+1)&&s[x+1][y] == s[x][y+1] && s[x][y+1] == '#')return 0;
        if(isvalid(x+1,y)&& s[x+1][y] == '#'){
            ++now;
            ++x;
            continue;
        }
        if(isvalid(x,y+1) && s[x][y+1] == '#'){
            ++now;
            ++y;
            continue;
        }
        return 0;
    }
    return  cnt == now;
}