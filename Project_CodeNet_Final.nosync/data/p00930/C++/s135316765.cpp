#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}
template<typename T> class segtree {
private:
  int n,sz,h;
  vector<pair<T, int> > node;
  vector<T> lazy;
  void eval(int k) {
    if(lazy[k]){
      node[k].first += lazy[k];
      if(k < n) {
        lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
      }
      lazy[k] = 0;
    }
  }
public:
  segtree(const vector<T>& v) : sz((int)v.size()), h(0) {
    n = 1;
    while(n < sz) n *= 2, h++;
    node.resize(2*n, pair<T, int>(numeric_limits<T>::max(), sz));
    lazy.resize(2*n, 0);
    for(int i = 0; i < sz; i++){
      node[i+n] = make_pair(v[i], i);
    }
    for(int i = n-1; i >= 1; i--){
      node[i] = min(node[2*i], node[2*i+1]);
    }
  }
  void range(int a, int b, T x, int k=1, int l=0, int r=-1){
    if(r < 0) r = n;
    eval(k);
    if(b <= l || r <= a){
      return;
    }
    if(a <= l && r <= b){
      lazy[k] += x;
      eval(k);
    }else{
      range(a, b, x, 2*k, l, (l+r)/2);
      range(a, b, x, 2*k+1, (l+r)/2, r);
      node[k] = min(node[2*k], node[2*k+1]);
    }
  }
  pair<T, int> query(int a, int b) {
    a += n, b += n - 1;
    for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
    b++;
    pair<T, int> res1 = make_pair(numeric_limits<T>::max(), sz);
    pair<T, int> res2 = make_pair(numeric_limits<T>::max(), sz);
    while(a < b) {
      if(a & 1) eval(a), res1 = min(res1, node[a++]);
      if(b & 1) eval(--b), res2 = min(res2, node[b]);
      a >>= 1, b >>= 1;
    }
    return min(res1, res2);
  }
  void print() {
    for(int i = 0; i < sz; i++){
      pair<T,int> p;
      p = query(i,i+1);
      cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
    }
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vi v(n+1);
  set<int> stl, str;
  for(int i=0;i<(n);++i) {
    if(s[i] == '(') {
      v[i+1] = v[i] + 1;
      stl.insert(i);
    } else {
      v[i+1] = v[i] - 1;
      str.insert(i);
    }
  }
  segtree<int> st(v);
  for(int i=0;i<(q);++i) {
    int idx; cin >> idx;
    idx--;
    if(stl.find(idx) != stl.end()) {
      stl.erase(idx);
      str.insert(idx);
      st.range(idx+1, n+1, -2);
      int pos = *(str.begin());
      cout << pos + 1 << endl;
      str.erase(pos);
      stl.insert(pos);
      st.range(pos+1, n+1, 2);
    } else {
      str.erase(idx);
      stl.insert(idx);
      st.range(idx+1, n+1, 2);
      int l = -1, r = n-1;
      while(r - l > 1) {
        int mid = (l + r) / 2;
        int mi = st.query(mid+1, n+1).first;
        if(mi >= 2) {
          r = mid;
        } else {
          l = mid;
        }
      }
      cout << r + 1 << endl;
      stl.erase(r);
      str.insert(r);
      st.range(r+1, n+1, -2);
    }
  }
}

