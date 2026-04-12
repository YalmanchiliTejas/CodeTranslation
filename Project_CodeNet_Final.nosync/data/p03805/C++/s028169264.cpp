#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
struct Edge{
int t;
};
struct Node{
  int no;
  vector<int> edge;
  bool have(int x){
    bool res=false;
    int n=edge.size();
    rep(i,n){
      if(edge[i]==x)res=true;
    }
    return res;
  }
};
signed main(){
  int n,m;cin>>n>>m;
  int res=0;
  vector<Node> node(n+1);
  vector<int> p(n-1);
  rep(i,n-1){
    p[i]=i+2;
  }
  rep(i,m){
    int a,b;cin>>a>>b;
    node[a].edge.push_back(b);
    node[b].edge.push_back(a);
  }
  do{
    int s=1;
    rep(i,n-1){
      if(!node[s].have(p[i])){
        goto FINE;
      }
      s=p[i];
    }
    res++;
    FINE:;
  }while(next_permutation(p.begin(),p.end()));
  cout<<res<<endl;
  return 0;
}
