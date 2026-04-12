#include <bits/stdc++.h>
 
using namespace std;
 
#define MD 1000000007
typedef long long int ll;

bool graph[8][8];//接続関係

int dfs(int v,int n,bool visited[8]){
    bool all_visited=true;
    for(int i=0;i<n;i++){//全ノード訪問済みかの確認
        if(visited[i]==false){
            all_visited=false;
        }
    }
    if(all_visited){//全ノード訪問済
        return 1;
    }
    int ret=0;
    for(int i=0;i<n;i++){
        if(graph[v][i]==false || visited[i]){//辺がないor既訪問なら無視
            continue;
        }
        visited[i]=true;//未訪問で辺があるので既訪問に
        ret+=dfs(i,n,visited);//再帰
        visited[i]=false;//これ重要．dfsの分岐先ノードを，一旦潜った後に再び未訪問に戻す作業．未訪問に戻しながらバックトラックするイメージ
    }
    return ret;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=graph[b-1][a-1]=true;
    }
    bool visited[8];
    for(int i=0;i<n;i++){
        visited[i]=false;//未訪問既訪問
    }
    visited[0]=true;//始点１は既訪問
    cout<<dfs(0,n,visited)<<endl;
    return 0;
}