#include <bits/stdc++.h>

#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define debug(a) cout << #a << ": " << a << endl

using namespace std;
const int oo = 1000000007;
const int MAXN = 300005; 

int n, q;
char s[MAXN];
set<int> pos;

struct Node {
  int m, val;
};

Node t[4*MAXN];

void propagate(const int &id, const int &l, const int &r) {
  int &x = t[id].val;
  if (x != 0) {
    fto(i, 0, 1) {
      t[2*id + i].m += x;
      t[2*id + i].val += x;
    }
    x = 0;
  }
}

void update(int id, int l, int r, const int &i, const int &j, const int &x) {
  if (j < l || i > r) return;
  if (i <= l && r <= j) {
    t[id].val += x;
    t[id].m += x;
    return;
  }
  // printf("%d %d %d %d\n", id, l, r, t[id].m);
  propagate(id, l, r);
  int m = (l + r)/2;
  update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
  t[id].m = min(t[2*id].m, t[2*id+1].m);
}

void check(int id, int l, int r) {
  // printf("%d %d %d %d %d\n", id, l, r, t[id].m, t[id].val);
  if (l < r) {
    int m = (l+r)/2;
    check(2*id, l, m);
    check(2*id+1, m+1, r);
  }  
}

int query(int id, int l, int r, const int x) {
  // printf("%d %d %d %d %d\n", id, l, r, x, t[id].m);
  if (t[id].m >= x)
    return l;
  if (l == r)
    return l+1;
  propagate(id, l, r);
  int m = (l+r)/2;
  int ans = query(2*id+1, m+1, r, x);
  if (ans == m+1)
    ans = query(2*id, l, m, x);
  return ans;
}

void flip(int i) {
  if (s[i] == '(') {
    s[i] = ')';
    update(1, 0, n-1, i, n-1, -2);
    pos.insert(i);
  } else {
    s[i] = '(';
    update(1, 0, n-1, i, n-1, 2);
    pos.erase(i);
  }
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s);

  fto(i, 0, n-1) {
    // debug(i);
    if (s[i] == ')') {
      pos.insert(i);
      update(1, 0, n-1, i, n-1, -1);
    } else 
      update(1, 0, n-1, i, n-1, 1);
  }

  // check(1, 0, n-1);

  fto(i, 1, q) {
    int p; scanf("%d", &p);
    --p;

    // debug(i);
    int ans;
    if (s[p] == '(') {
      flip(p);
      ans = *pos.begin();
    } else {
      flip(p);
      // if (i == 2)
      //   check(1, 0, n-1);
      ans = query(1, 0, n-1, 2);
    }
    
    flip(ans);
    // printf("%s\n", s);
    // for(int x: pos)
    //   printf("%d ", x);
    // puts("");
    printf("%d\n", ans+1);
  }
  
  return 0;
}
