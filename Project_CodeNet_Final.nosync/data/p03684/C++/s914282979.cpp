#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
#include <set>
#include <bitset>
using namespace std;

#define ll long long
#define N 200000
pair<int,int> X[N],Y[N];
pair<int,pair<int,int> > all[N];

int dsu[N];

int f(int x) {
  if(x==dsu[x]) {
    return x;
  }
  return dsu[x] = f(dsu[x]);
}
bool merge(int x,int y) {
  x = f(x),y=f(y);
  if(x==y) {
    return false;
  } else {
    dsu[x] = y;
    return true;
  }
}
void solve() {
  int n;scanf("%d ", &n);
  for(int i=0;i<n;++i) {
    scanf("%d %d ", &X[i].first,&Y[i].first);
    X[i].second = Y[i].second = i;
    dsu[i] = i;
  }
  sort(X,X+n);
  sort(Y,Y+n);
  int pos = 0;
  for(int i=0;i<n-1;++i) {
    all[pos++] = make_pair(X[i+1].first-X[i].first,make_pair(X[i].second,X[i+1].second));
    all[pos++] = make_pair(Y[i+1].first-Y[i].first,make_pair(Y[i].second,Y[i+1].second));
  }
  sort(all,all+pos);
  long long ret = 0;
  for(int i=0;i<pos;++i) {
    int w = all[i].first;
    int a = all[i].second.first,b = all[i].second.second;
    if(merge(a,b)) {
      ret += w;
    }
  }
  printf("%lld\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
