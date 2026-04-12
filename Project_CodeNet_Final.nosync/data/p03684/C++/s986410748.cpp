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
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
unifnd tfd;
in n;
vector<pair<in,in> > bx,by;
vector<pair<in,pair<in,in> > > egs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  tfd.ini(n);
  in tx,ty;
  forn(z,n){
    cin>>tx>>ty;
    bx.PB(MP(tx,z));
    by.PB(MP(ty,z));
  }
  sort(all(bx));
  sort(all(by));
  forn(z,n-1){
    egs.PB(MP(bx[z+1].first-bx[z].first,MP(bx[z].second,bx[z+1].second)));
    egs.PB(MP(by[z+1].first-by[z].first,MP(by[z].second,by[z+1].second)));
  }
  sort(all(egs));
  in sm=0;
  in hv=0;
  in nxt=0;
  while(hv<n-1){
    if(tfd.fnd(egs[nxt].second.first)==tfd.fnd(egs[nxt].second.second)){
      ++nxt;
      continue;
    }
    tfd.uni(egs[nxt].second.first,egs[nxt].second.second);
    sm+=egs[nxt].first;
    ++hv;
    ++nxt;
  }
  cout<<sm<<endl;
  return 0;
}
