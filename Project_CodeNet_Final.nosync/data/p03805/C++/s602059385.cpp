#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N,M;
int a[30],b[30];
vi edge[8];
void add_edge(int from,int to){
  edge[from].push_back(to);
  edge[to].push_back(from);  
}
void dfs(int v,int S,int& x){
  if(S==(1<<N)-1) x++;
  rep(i,edge[v].size()){
    int w=edge[v][i];
    if(!((S>>w)&1)){ dfs(w,S|1<<w,x);}
  }
}
int main(){
  cin>>N>>M;
  rep(i,M){cin>>a[i]>>b[i];a[i]--;b[i]--;}
  rep(i,M) add_edge(a[i],b[i]);
  int res=0;
  dfs(0,1,res);
  prin(res);
  return 0;
}
