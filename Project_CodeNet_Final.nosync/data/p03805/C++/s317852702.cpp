#include <cstdio>
#include <vector>
using namespace std;
int used[8];
bool G[8][8];
int N,M;
int ans;
bool all_used(){
  for(int i=0;i<N;i++){
    if(used[i]==false)return false;
  }
  return true;
}
void dfs(int now,int num){
  used[now]=1;
  //printf("%d %d\n",now,num);
  if(num==N){
    ans++;
    
    return ;
  }
  for(int i=0;i<N;i++){
    if(G[now][i]==true && used[i]==0){
      dfs(i,num+1);
      used[i]=0;
    }
  }
}
int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    G[a][b]=1;
    G[b][a]=1;
  }
  dfs(0,1);
  printf("%d\n",ans);
  return 0;

}
