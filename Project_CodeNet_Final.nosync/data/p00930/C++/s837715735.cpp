#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Computational cost: O( N + Q log N )
// using segment trees for paren depths and # of close parens + 1-pass search

int ge_pow2(int n)
{
  int N = 1;
  for(int i = n; i > 0; i >>= 1, N<<=1 );
  if(2*n == N) N = n;
  return N;
}

// segment tree (min, max, sum)?
// lazy updates for (min,max) only
struct tree {
  static const int BIG = 2*512*1024;
  vector<int> ds;  // min. depth of open parens
  vector<int> ds2; // max. depth of open parens
  vector<int> ods;
  vector<int> ss;  // close paren -> 1: sum of close parens
  vector<int> us;
  const int n;
  const int N;
  tree(const vector<char> &ps) : n(ps.size()), N(ge_pow2(n)) {
    ds.resize(2*N);
    ds2.resize(2*N);
    ss.resize(2*N);
    us.resize(2*N);
    ods.resize(2*N);
    for(int i = 0; i < 2*N; i++) {
      us[i] = 0;
      ds[i] = BIG;
      ds2[i] = -BIG;
      ods[i] = BIG;
      ss[i] = 0;
    }
    int d = 0;
    for(int i = 0; i < n; i++) {
      if(ps[i] == ')') {
        ods[i+N] = d;
        ds[i+N] = BIG;
        ds2[i+N] = -BIG;
        d--;
        ss[i+N] = 1;
      } else {
        ods[i+N] = d;
        ds[i+N] = d;
        ds2[i+N] = d;
        d++;
      }
    }
    // initialize the internal nodes
    for(int i = N-1; i > 0; i--) {
      ds[i] = min(ds[i*2], ds[i*2+1]);
      ds2[i] = max(ds2[i*2], ds2[i*2+1]);
      ss[i] = ss[i*2] + ss[i*2+1];
    }
  }
  int rightmost_open_2nd() {
    return rightmost_open_2nd_rec(1, 0, N);
  }
  int rightmost_open_2nd_rec(int k, int l, int r) {
    if(r - l == 1) return k - N;
    if(us[k] != 0) {
      push(2*k  , us[k], l, (l+r)/2);
      push(2*k+1, us[k], (l+r)/2, r);
      us[k] = 0;
    }
    if( ds[2*k+1] <= 1 && 1 <= ds2[2*k+1] ) {
      return rightmost_open_2nd_rec(2*k+1, (l+r)/2, r);
    } else {
      return rightmost_open_2nd_rec(2*k, l, (l+r)/2);
    }
  }
  int leftmost_close() {
    return leftmost_close_rec(1, 0, N);
  }
  int leftmost_close_rec(int k, int l, int r) {
    if(r - l == 1) return k - N;
    if( ss[2*k] >= 1 ) {
      return leftmost_close_rec(2*k, l, (l+r)/2);
    } else {
      return leftmost_close_rec(2*k+1, (l+r)/2, r);
    }
  }
  void open(int j) {
    write_s(j, 0);
    clear(j, 1, 0, N); // path clear (to make ods[N+j] valid);
    write_d(j, ods[N+j]); // put the depth ods[N+j]
    update_region(j+1, n, 1, 2, 0, N);  // update the depths by +2
  }
  void close(int j) {
    write_s(j, 1);
    write_d(j, BIG); // remove the depth 
    update_region(j+1, n, 1, -2, 0, N);  // update the depths by -2
  }
  void write_s(int i, int v) {
    i += N;
    ss[i] = v;
    for(i >>=1; i > 0; i >>=1) ss[i] = ss[i*2] + ss[i*2+1];
  }
  void clear(int i, int k, int l, int r) {
    min_max_d2(i, i+1, k, l, r);
  }
  void write_d(int i, int v) {
    clear(i, 1, 0, N); // clear the path
    i += N;
    ds[i] = v;
    ds2[i] = v > n ? -v : v;
    for(i >>=1; i > 0; i >>=1) {
      ds[i]  = min(ds[i*2] , ds[i*2+1] );
      ds2[i] = max(ds2[i*2], ds2[i*2+1]);
    }
  }
  void push(int k, int u, int l, int r) {
    us[k] += u;
    ds[k] += u;
    ds2[k] += u;
    if(l - r == -1) { ods[k] += u; us[k] = 0; }
  }
  void min_max_d2(int i, int j, int k, int l, int r) {
    if(r <= i || j <= l) return;
    if(us[k] != 0) {
      push(2*k  , us[k], l, (l+r)/2);
      push(2*k+1, us[k], (l+r)/2, r);
      us[k] = 0;
    }
    if(i <= l && r <= j) {
      // usually, returns the values here.
      return;
    }
    min_max_d2(i, j, k*2    , l, (l+r)/2);
    min_max_d2(i, j, k*2 + 1, (l+r)/2, r);
  }
  void update_region(int i, int j, int k, int v, int l, int r) {
    if(r <= i || j <= l) return;
    if(i <= l && r <= j) {
      push(k, v, l, r);
    } else {
      update_region(i, j, k*2    , v, l, (l+r)/2);
      update_region(i, j, k*2 + 1, v, (l+r)/2, r);
      ds[k]  = min(ds[k*2] , ds[k*2+1] );
      ds2[k] = max(ds2[k*2], ds2[k*2+1]);
    }
  }
  bool is_close(int j) {
    return ss[j+N] == 1;
  }
};
  
int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  int q;
  cin >> q;
  vector<char> ps;
  for(int i = 0; i < n; i++) {
    char p;
    cin >> p;
    ps.push_back(p);
  }
  tree t(ps);
  for(int i = 0; i < q; i++) {
    int j;
    cin >> j;
    j--;
    if(t.is_close(j)) {
      t.open(j);
      int k = t.rightmost_open_2nd();
      cout << (k+1) << endl;
      t.close(k);
    } else {
      t.close(j);
      int k = t.leftmost_close();
      cout << (k+1) << endl;
      t.open(k);
    }
  }
}


