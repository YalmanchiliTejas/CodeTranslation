#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define repr(i,n) for(ll i=n;i>=0;i--)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const int MOD = 1e9 +7;

int h,w;
char field[10][10];

void dfs(int x,int y){
    field[x][y] ='.';
    bool flag =false;
    if(!flag &&0<=x+1 && x+1<h && field[x+1][y] =='#'){
        flag =true;
        dfs(x+1,y);
    }
    if(!flag &&0<=y+1 && y+1<w && field[x][y+1] =='#'){
        flag =true;
        dfs(x,y+1);
    }
    return ;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>field[i][j];
        }
    }
    dfs(0,0);
    bool can=true;
    rep(i,h){
        rep(j,w){
            if(field[i][j]=='#') can=false;
        }
    }
    if(can){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}