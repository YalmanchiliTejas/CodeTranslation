#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
typedef pair<int,int> P;
using ll = long long;

int h,w;
vector<vector<char>> field;

bool dfs(int x,int y){
    if(field[x+1][y]=='#'&&field[x][y+1]=='#') return false;
    if(field[x-1][y]=='#'&&field[x][y-1]=='#') return false;
    if(x==h&&y==w) return true;
    if(field[x+1][y]=='#'){
        if(dfs(x+1,y)) return true;
    }
    if(field[x][y+1]=='#'){
        if(dfs(x,y+1)) return true;
    }
    return false;
}

int main(){
    cin>>h>>w;
    field.resize(h+3,vector<char>(w+3));
    rep(i,h) rep(j,w) cin>>field[i][j];
    if(dfs(1,1)) cout<<"Possible";
    else cout<<"Impossible";
}