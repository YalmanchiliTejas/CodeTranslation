#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int m[9][9];
int n,M;
int p[9];
int ans=0;

void dfs(int x,int d){
  p[x]=1;
  for(int i=1;i<=n;i++){
    if(m[x][i]==0) continue;
    if(p[i]==1) continue;
    dfs(i,d+1);
  }
  if(d==n) ans++;
  p[x]=0;
}

int main(){
  cin>>n>>M;
  int a,b;

  for(int i=0;i<M;i++){
    cin>>a>>b;
    m[a][b]=1;
    m[b][a]=1;
  }

  dfs(1,1);
  cout<<ans<<endl;
  return 0;
}
