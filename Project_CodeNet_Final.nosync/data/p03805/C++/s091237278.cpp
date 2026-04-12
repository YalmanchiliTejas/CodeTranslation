#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(x) for(auto it=(x).begin();it!=(x).end();it++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;
int n,m;
vector<vector<bool>> v(8,vector<bool>(8,false));

int dfs(int x,vector<bool> visited){
    bool all_visit=true; //全部訪問済みかどうか
    rep(i,0,n){
        if(!visited[i])all_visit=false;
    }
    if(all_visit)return 1;
    
    int ret=0; //答え
    
    rep(i,0,n){//全ての頂点を見る中で
        if(!v[x][i])continue; //そもそも辺が張られてなければ飛ばす
        if(visited[i])continue; //既に訪問済みなら飛ばす
        
        visited[i]=true; //訪問済みにする
        ret+=dfs(i,visited); //その辺を始点にして再帰
        visited[i]=false; //これをしないと、for文回す中で独立した施行にならない
    }
    
    return ret; //retを返すよお
}

int main(){
    cin>>n>>m;
    rep(i,0,m){ //グラフを隣接行列で構築する
        int x,y;
        cin>>x>>y;
        x--; y--;
        v[x][y]=true;
        v[y][x]=true;
    }
    
    vector<bool> visited(8,false); //訪問済みかどうかを格納する配列
    visited[0]=true;
    
    cout<<dfs(0,visited)<<endl;
    
    
    return 0;
}
