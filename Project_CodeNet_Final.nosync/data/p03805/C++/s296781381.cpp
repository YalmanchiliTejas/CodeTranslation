#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
bool graph[8][8]={};
int n,m;
int cnt=0;
void dfs(int now,vector<int> visited){
    visited[now]=true;
    bool all_visited=true;
    rep(i,n){
        if(!visited[i]){
            all_visited = false;
        }
    }
    if(all_visited){
        cnt++;//すべて訪問済みの場合のみ、条件を満たしている
        return ;
    }
    rep(i,n){
        if(!visited[i] && graph[now][i]){
            //頂点nowとiが結ばれており、iが未訪問ならばさらに探索する
            //cout<<now<<"->"<<i<<endl;
            dfs(i,visited);
        }
    }
}
int main(){
    cin>>n>>m;
    vector<int> visited(n,false);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a][b]=graph[b][a]=true;
    }
    dfs(0,visited);
    cout<<cnt<<endl;
}