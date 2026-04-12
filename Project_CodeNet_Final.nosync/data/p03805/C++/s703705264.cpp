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
    bool all_visit=true;
    rep(i,0,n){
        if(!visited[i])all_visit=false;
    }
    if(all_visit)return 1;
    
    int ret=0;
    
    rep(i,0,n){
        if(!v[x][i])continue;
        if(visited[i])continue;
        
        visited[i]=true;
        ret+=dfs(i,visited);
        visited[i]=false;
    }
    
    return ret;
}

int main(){
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        x--; y--;
        v[x][y]=true;
        v[y][x]=true;
    }
    
    vector<bool> visited(8,false);
    visited[0]=true;
    
    cout<<dfs(0,visited)<<endl;
    
    
    return 0;
}