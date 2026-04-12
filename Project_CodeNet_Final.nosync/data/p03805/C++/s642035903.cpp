#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using P=pair<int,int>;


int i,j,n,m,ans=0;
vector<bool> visit;
void dfs(int,int);
Graph G;

int main(){
    cin>>n>>m;
    G.resize(n);
    visit.assign(n,0);

    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;a--;b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    
    visit[0]=1;
    dfs(n,0);
    
    cout<<ans<<endl;
    return 0;
}
void dfs(int k,int state){//state:今いる場所
    
    for(auto next:G[state]){
        if(visit[next]!=1){//訪れていないとき
            visit[next]=1;//訪れた
            dfs(k-1,next);//次へ
            visit[next]=0;
            /*一通り訪れ終えたらstate以降を元に戻し、
            別の道で一筆書き可能か調べる*/
        }
    }

    if(k==1){//適パターン(一筆書き可能ならば、n-1辺のみを通るので、k==1ならば可能)　
        ans++;
        return;    
    }

    return;
}