#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
bool seen[8];
vector<vector<bool>> graph;
void dfs(int s,int n,int *ans){
   bool all_seen=true;
   for(int i=0;i<n;i++){
      if(seen[i]==false){
         all_seen=false;
         break;
      }
   }
   if(all_seen){
      *ans=*ans+1;
      return;
   }
   for(int i=0;i<n;i++){
      if(graph[s][i]){
         if(seen[i]==false){
            seen[i]=true;
            dfs(i,n,ans);
            seen[i]=false;
         }
      }
   }
}

int main(void){
   int N,M;
   cin>>N>>M;
   vector<int> a(M),b(M);
   graph.resize(N);
   for(int i=0;i<N;i++){
      graph[i].resize(N);
   }
   for(int i=0;i<M;i++){
      cin>>a[i]>>b[i];
      a[i]--;
      b[i]--;
      graph[a[i]][b[i]]=true;
      graph[b[i]][a[i]]=true;
   }
   for(int i=0;i<N;i++){
      seen[i]=false;
   }
   seen[0]=true;
   int ans=0;
   dfs(0,N,&ans);
   cout<<ans<<endl;
   return 0;
}