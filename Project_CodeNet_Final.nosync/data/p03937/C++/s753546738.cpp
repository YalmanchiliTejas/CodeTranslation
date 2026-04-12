#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
bool flag=false;
using pii = pair<int, int>;
int hoge=0;
int h,w;
bool inrange(int y,int x){return (0<=x&&x<w&&0<=y&&y<h);}
void dfs(int cnt,pii now,vector<vector<char>>graph){
    if(cnt==hoge&&now==pii(h-1,w-1))flag=true;
    if(inrange(now.first+1,now.second)&&graph[now.first+1][now.second]=='#'){
        dfs(cnt+1,pii(now.first+1,now.second),graph);
    }
    if(inrange(now.first,now.second+1)&&graph[now.first][now.second+1]=='#'){
        dfs(cnt+1,pii(now.first,now.second+1),graph);
    }
    return;
}
int main(){
    cin>>h>>w;
    vector<vector<char>>graph(h,vector<char>(w));
    rep(i,h)rep(j,w){
        cin>>graph[i][j];
        if(graph[i][j]=='#')hoge++;
    }
    dfs(1,pii(0,0),graph);
    if(flag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
