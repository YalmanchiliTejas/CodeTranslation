#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in n;
VVI egs;
void first(){
  cout<<"First"<<endl;
  exit(0);
}
void second(){
  cout<<"Second"<<endl;
  exit(0);
}
in dfs(in u, in pr){
  in avc=0;
  forv(i,egs[u]){
    if(egs[u][i]==pr)
      continue;
    avc+=dfs(egs[u][i],u);
  }
  if(avc>=2)
    first();
  if(avc==0)
    return 1;
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  egs.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  if(dfs(0,0)){
    first();
  }
  second();
  return 0;
}
