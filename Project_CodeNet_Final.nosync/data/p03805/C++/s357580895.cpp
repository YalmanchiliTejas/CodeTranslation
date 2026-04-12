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
VVI d;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  d=VVI(n,VI(n));
  in a,b;
  forn(z,m){
    cin>>a>>b;
    --a;
    --b;
    d[a][b]=d[b][a]=1;
  }
  VI p;
  in sm=0;
  forn(i,n)
    p.PB(i);
  do{
    bool ok=1;
    forn(i,n-1)
      ok&=d[p[i]][p[i+1]];
    sm+=ok;
  }while(next_permutation(p.begin()+1,p.end()));
  cout<<sm<<endl;
  return 0;
}
