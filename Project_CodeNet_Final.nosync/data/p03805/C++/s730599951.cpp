#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

bool g[10][10];

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> v;
  rep(i,n-1) v.push_back(i+1);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a][b]=true;
    g[b][a]=true;
  }
  int ans=0;
  do{
    if(g[0][v[0]]==false) continue;
    bool flag=true;
    rep(i,n-2){
      if(g[v[i]][v[i+1]]==false) flag=false;
    }
    if(flag) ans++;
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;    
  return 0;
}