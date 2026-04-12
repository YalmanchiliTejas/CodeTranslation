#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
vector<int> G[9];
int n;
int cnt=0;
void dfs(int now,vector<int> visit){
    visit[now] = true;
    bool end=true;
    rep(i,n){
        if(!visit[i]){
            end = false;
        }
    }
    if(end){
        cnt++;
        return ;
    }
    for(int i=0;i<G[now].size();i++){
        int child = G[now][i];
        if(!visit[child]){
            dfs(child,visit);
        }
    }
    
}
int main(){
    int m;
    cin>>n>>m;
    vector<int> visited(n,false);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    /*
    for(int i=0;i<n;i++){
        cout << "G[" <<i <<"]={";
        for(unsigned int j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
    */
    dfs(0,visited);
    cout<<cnt<<endl;
}
