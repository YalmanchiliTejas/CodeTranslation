#include<bits/stdc++.h>
#include<queue>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M;
  cin>>N>>M;
  int perm[N],ans=0;
  bool tmp=true;
  RREP(i,1,N+1) perm[i-1]=i;
  int g[10][10]={};
  REP(i,M){
    int a,b;
    cin>>a>>b;
    g[a][b]=1,g[b][a]=1;
  }
  do{
    if(perm[0]!=1)continue;
    tmp=true;
    //REP(i,N)cout<<perm[i];
    //cout<<endl;
    tmp=true;
    REP(i,N-1)if(g[perm[i]][perm[i+1]]!=1) tmp=false;
    if(tmp)ans++;
  }while(next_permutation(perm,perm+N));
  cout<<ans;

  return 0;
}