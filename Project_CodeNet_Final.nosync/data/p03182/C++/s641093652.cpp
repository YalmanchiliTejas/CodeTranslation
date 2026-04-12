#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
long long tr[maxn<<2], lazy[maxn<<2];
void push(int id, int l, int r){
  if(lazy[id]){
    tr[id] += lazy[id];
    if(l != r){
      lazy[id<<1] += lazy[id];
      lazy[id<<1|1] += lazy[id];
    }
    lazy[id] = 0;
  }
}
void add(int id, int l, int r, int x, int y, long long v){
  push(id, l, r);
  if(l > y || r < x) return;
  if(x <= l && r <= y) {
    lazy[id] += v;
    push(id, l, r);
    return;
  }
  int mid = (l + r)>>1;
  add(id<<1, l, mid, x, y, v);
  add(id<<1|1, mid + 1, r, x, y, v);
  tr[id] = max(tr[id<<1], tr[id<<1|1]);
}
long long sum(int id, int l, int r, int x, int y){
  push(id, l, r);
  if(l > y || r < x) return (-(1ll<<60));
  if(x <= l && r <= y) return tr[id];
  int mid = (l + r)>>1;
  return max(sum(id<<1, l, mid, x, y), sum(id<<1|1, mid + 1, r, x, y));
}
vector<pair<int,int> > upd[maxn];
int main(){
  int n, m; cin >> n >> m;
  vector<long long> psum(n + 2, 0);
  for(int i = 0; i < m; i++){
    int l, r, w; cin >> l >> r >> w;
    upd[l].push_back({r, -w});
    upd[r + 1].push_back({l, w});
    psum[l] += w;
    psum[r + 1] -= w;
  }
  for(int i = 2; i <= n; i++) psum[i] += psum[i - 1];
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    for(auto j : upd[i]) add(1, 0, n, min(i, j.first), max(i - 1, j.first), j.second);
    long long now = sum(1, 0, n, 0, i - 1) + psum[i];
    ans = max(ans, now);
    add(1, 0, n, i, i, now);
  }
  cout << ans << endl;
  return 0;
}
