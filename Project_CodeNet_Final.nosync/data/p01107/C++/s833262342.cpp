#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int dfs(int i, int j, vector<string> &g){
    int res=0;
    if(g[i][j] == '#') return res;
    g[i][j] = '#';
    int h=g.size()-2, w=g[0].size()-2;
    if((i==1 or i==h) and (j==1 or j==w)){
        res++;
    }
    for(int d=0; d<4; d++){
        res += dfs(i+di[d], j+dj[d], g);
    }
    return res;
}
bool check(vector<string> &g){
    int h=g.size()-2, w=g[0].size()-2;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if((i==1 or i==h) and (j==1 or j==w)){
                continue;
            }
            auto tmp = g;
            tmp[i][j] = '#';
            if(dfs(1, 1, tmp) != 4){
                return false;
            }
        }
    }
    return true;
}

int main(){
    while(1){
        int h,w;
        cin >> h >> w;
        if(h == 0) break;
        vector<string> g(h+2, string(w+2, '#'));
        for(int i=1; i<=h; i++){
            cin >> g[i];
            g[i] = "#" + g[i] + "#";
        }
        if(check(g)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

