#include<cstdio>

int graph[10][10];
int n,ans=0;

void search(int came[],int v){
  int i;
  for(i=0;i<n;i++)
    if(came[i]==0) break;
  if(i==n){
    ans++;
    return;
  }
  for(i=0;i<n;i++){
    if(graph[v][i]==1 && came[i]==0){
      came[i]=1;
      search(came,i);
      came[i]=0;
    }
  }
}

int main(void){
  int m;
  int came[10]={};

  scanf("%d %d",&n,&m);
  int a,b;
  for(int i=0;i<m;i++){
    scanf("%d %d",&a,&b);
    graph[a-1][b-1]=1;
    graph[b-1][a-1]=1;
  }

  came[0]=1;
  search(came,0);

  printf("%d\n",ans);

  return 0;
}
