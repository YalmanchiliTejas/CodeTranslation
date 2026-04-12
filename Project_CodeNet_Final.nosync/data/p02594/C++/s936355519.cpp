#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define mp make_pair
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int isprime(int n){
    int count =0;
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)count++;
    if(count)return 0;
    return 1;
}

void dfs(vector<int>adj[],int u,int visited[]) {
       visited[u] = 1;
       for (int i = 0; i < adj[u].size(); i++) {
       int v = adj[u][i];
       if (visited[v]) {
       continue;
       }
      dfs(adj,v,visited);
      }
      }
void bfs(vector<int>adj[],int u,int visited[],int layer[]){
    queue<int> q;
    layer[u]=0;
    visited[u]=1;
    q.push(u);
    while(!q.empty()){
         u = q.front();
         q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                q.push(v);
                layer[v]=layer[u]+1;
                visited[v]=1;
            }
        }
    }
}    
void bfs01(vector<pair<int,int> >adj[],int start,int d[]){
    deque<int> q;
    q.pf(start);
    d[start]=0;
    while(!q.empty()){
         int u = q.front();
         q.pop_front();
        for(int i=0;i<adj[u].size();i++){
           if(d[adj[u][i].first]>d[u]+adj[u][i].second){
               d[adj[u][i].first] = d[u]+adj[u][i].second;
               if(adj[u][i].second==0)
               q.pf(adj[u][i].first);
               else 
               q.pb(adj[u][i].first);
               
           } 
          
        }
    }
   
}
void addedge(vector<int>adj[],int a,int b){
    adj[a].pb(b);
    adj[b].pb(a);
}

int main(){
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes";
    else cout<<"No";
    
    return 0;
}

