#include <bits/stdc++.h>
using namespace std;
const int INF=100000000;
bool g[10][10];
int main()
{
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;a--;b--;
    g[a][b]=g[b][a]=true;
    //cout<<g[a][b]<<" "<<g[b][a]<<endl;
  }
  vector<int>ord(n);
  for(int i=0;i<n;i++)ord[i]=i;
  int res=0;
  do{
    if(ord[0]!=0)break;
    bool ok=true;
    for(int i=0;i+1<n;i++){
      int from=ord[i];
      int to=ord[i+1];
      if(!g[from][to])ok=false;
    }
    if(ok)res++;
  }while(next_permutation(ord.begin(),ord.end()));
  cout<<res<<endl;
}