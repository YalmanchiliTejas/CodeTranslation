#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int dfs(int v,int N,vector<bool>seen,const Graph G){
    bool all_visited=true;
    rep(i,N){
        if(seen[i]==false){
            all_visited=false;//訪れていないところがあったらfalse
        }
    }
    if(all_visited){
        return 1;
    }//全ての頂点を巡っていれば1を返す
    //まだ全ての頂点を巡っていないとき
    int ret=0;//そこから先で考えられるルート数
    rep(i,N){
        if(G[v][i]==0){
            continue;
        }//経路がなければパス
        if(seen[i]){
            continue;
        }//すでに通った頂点ならパス
        seen[i]=true;//訪れたことにして
        ret+=dfs(i,N,seen,G);//答えにそれより先の答えを追加
        //ここでわたしたvisitedを元に戻す
        seen[i]=false;//もう一度訪れてないことにして続きの処理へ
    }
    return ret;
}

int main(){
    int N,M;cin>>N>>M;
    Graph G(N,vector<int>(N,0));
    rep(i,M){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a][b]=1;
        G[b][a]=1;
    }
    vector<bool>seen(N,false);
    seen[0]=true;
    cout<<dfs(0,N,seen,G)<<endl;
}