#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 100005;

int X[N], Y[N];
bool used[N];
set<pii > sx, sy;
set<pii >::iterator it;
set<pii > s;

void insertX(int x, int id) {
  if(!sx.size()) return;
  it = sx.lower_bound(mp(x, id));
  if(it == sx.end()) {
    pii p = *sx.rbegin();
    s.insert(mp(abs(p.FF - x), p.SS));
    return;
  }
  s.insert(mp(abs((*it).FF - x), (*it).SS));
  if(it == sx.begin()) return;
  it--;
  s.insert(mp(abs((*it).FF - x), (*it).SS));
}

void insertY(int x, int id) {
  if(!sy.size()) return;
  it = sy.lower_bound(mp(x, id));
  if(it == sy.end()) {
    pii p = *sy.rbegin();
    s.insert(mp(abs(p.FF - x), p.SS));
    return;
  }
  s.insert(mp(abs((*it).FF - x), (*it).SS));
  if(it == sy.begin()) return;
  it--;
  s.insert(mp(abs((*it).FF - x), (*it).SS));
}

int main() {
  int n;
  S(n);
  rep(i,0,n) {
    S2(X[i],Y[i]);
    if(i) {
      sx.insert(mp(X[i], i));
      sy.insert(mp(Y[i], i));
    }
  }
  LL ans = 0;
  used[0] = true;
  insertX(X[0], 0);
  insertY(Y[0], 0);
  rep(i,1,n) {
    pii p = *s.begin();
    s.erase(p);
    int x = p.SS;
    if(used[x]) {
      i--;
      continue;
    }
    sx.erase(mp(X[x], x));
    sy.erase(mp(Y[x], x));
    used[x] = true;
    ans += p.FF;
    insertX(X[x], x);
    insertY(Y[x], x);
  }
  cout << ans << "\n";
  return 0;
}
