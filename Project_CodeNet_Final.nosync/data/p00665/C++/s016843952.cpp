#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<cassert>
#define rep(i,n) for(int i=0;i<n;i++)
#define fr(i,c) for(__typeof (c.begin()) i=c.begin(); i!=c.end(); i++)
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

struct S{
  char s[11];
  int x;
  bool operator<(const S &r)const{
    if(x!=r.x)return x>r.x;
    return strcmp(s,r.s)<0;
  }
};
S chara[100000];
int n,m,k,l;

vector<S> like, dislike;
ll calc(int m){
  ll need=0;
  if(dislike.size()<k-m+1)return 0;
  rep(i,m){
    //cerr<<"hoge: "<<dislike[k-m].x-like[i].x<<endl;
    need+=max(0,dislike[k-m].x-like[i].x+
    (strcmp(dislike[k-m].s,like[i].s)<0));
  }
  //cerr<<"m: "<<m<<" need: "<<need<<endl;
  return need;
}

int main(){
  while(scanf("%d%d%d%d",&n,&m,&k,&l),n){
    set<string> names;
    rep(i,n)scanf("%s%d",chara[i].s,&chara[i].x);
    rep(i,m){
      char in[11]; scanf("%s",in);
      names.insert(string(in));
    }
    like.clear(); dislike.clear();
    rep(i,n){
      if(names.count(chara[i].s))like.pb(chara[i]);
      else dislike.pb(chara[i]);
    }
    sort(all(like)); sort(all(dislike));
    //rep(i,dislike.size())cerr<<dislike[i].s<<" "<<dislike[i].x<<endl;
    
    int lo=0, hi=min(m,k)+1, mid;
    while(lo+1<hi){
      mid=(lo+hi)/2;
      if(calc(mid)<=l)lo=mid; else hi=mid;
    }
    printf("%d\n",lo);
  }
  return 0;
}