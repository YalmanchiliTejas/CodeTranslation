#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
  int n,m,ans=0;
  vector<int>graph[100];
  vector<int>perm;
  
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for(int i=2;i<=n;i++){
    perm.push_back(i);
  }
  
  do{
    int now=1,next;
    for(int i=0;i<n-1;i++){
      next=perm[i];
      if(find(graph[now].begin(),graph[now].end(),next)==graph[now].end()){
	break;
      }
      if(i==n-2) ans++;
      now=next;
    }
  }while(next_permutation(perm.begin(),perm.end()));

  printf("%d\n",ans);
  
  return 0;
}
