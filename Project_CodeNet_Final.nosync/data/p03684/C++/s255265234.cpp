#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

/* UnionFind */

struct UnionFind{
  vector<int> data, tree_size;
  UnionFind(int s):data(s,-1),tree_size(s,1) {}
  
  int root(int x){
    if(data[x]==-1) return x;
    return data[x]=root(data[x]);
  }
  
  bool set(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y) return false;
    data[y]=x;
    tree_size[x] += tree_size[y];
    tree_size[y] = 0;
    return true;
  }
  
  bool check(int x,int y){
    x=root(x);
    y=root(y);
    return x==y;
  }
  
  int size(int x){
    return tree_size[root(x)];
  }
  
};


int main(){
  int n,x[SIZE],y[SIZE];
  vector<pair<int,int> > vec1,vec2;
  
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    scanf("%d%d",x+i,y+i);

    vec1.push_back({x[i],i});
    vec2.push_back({y[i],i});
  }

  sort(vec1.begin(),vec1.end());
  sort(vec2.begin(),vec2.end());

  vector<pair<int,pair<int,int> > > vec;

  for(int i=0;i<vec1.size()-1;i++){
    vec.push_back({vec1[i+1].first - vec1[i].first,{vec1[i].second,vec1[i+1].second}});
  }
  
  for(int i=0;i<vec2.size()-1;i++){
    vec.push_back({vec2[i+1].first - vec2[i].first,{vec2[i].second,vec2[i+1].second}});
  }

  sort(vec.begin(),vec.end());

  UnionFind uf(n);
  ll ans = 0;
  
  for(int i=0;i<vec.size();i++){
    if(uf.set(vec[i].second.first, vec[i].second.second))
      ans += vec[i].first;
  }

  printf("%lld\n",ans);
  
  return 0;
}
