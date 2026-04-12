#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1e17;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
struct SegmentTree{
  int N;
  vector<int> node;
  public :
    void intit(vector<int>v){
      int sz = v.size();
      N=1;
      while(N<sz) N*=2;
      node.resize(N);
      for(int i=0 ; i<sz ; i++) node[i+N-1] = v[i];
      for(int i=N-2 ; i>=0 ; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void update(int x, int val){
      x += N-1;
      node[x+N-1] = val;
      while(x>0){
        x = (x-1)/2;
        node[x] = min(node[x*2+1], node[x*2+2]);
      }
    }
    int getmin(int a, int b, int k, int l, int r){
      if(b<=l || r<=a) return inf;
      else if(a<=l && r<=b) return node[k];
      else{
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
      }
    }
};
struct func{
  int num, denom;
  func(int num, int denom=1)
    : num(num), denom(denom)
    {

    }
  ~func(){

  }
};
func operator +(func const &l, func const &r){
  if(l.denom==r.denom) return func(l.num+r.num, l.denom);
  return func(l.num*r.denom+r.num*l.denom, l.denom*r.denom);
}
struct IntLike{
  int data;
  IntLike(int data)
    : data(data)
    {}
  IntLike operator +(IntLike const &right)
  {
    return IntLike(data + right.data);
  }
};
struct array3{
  int storage[3];
  array3(array3 const &other){
    copy(begin(other.storage), end(other.storage), begin(storage));
  }
  int & operator [](size_t i){
    return storage[i];
  }
};
/*template <typename Array>
struct array_iterator_begin{
  Array & a;
  array_iterator_begin(Array & a)
    : a( a )
    {}
  typename Array::reference array_iterator_begin::operator *(){
    return a[0];
  }
};*/
/*
template <typename Array>
struct array_iterator{
  Array & a;
  size_t i;
  array_iterator(Array & a, size_t i)
    : a(a), i(i) {}
  typename Array::reference operator *(){ /////ここよくわかんない。違うかもしれん
    return a[i];
  }
  array_iterator & array_iterator::operator ++(){
    ++i;
    return *this;
  }
};
template <typename T, size_t N>
struct array{
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = size_t;
  using iterator = array_iterator<array>;

  value_type storage[N];
  reference operator [](size_type i){
    return storage[i];
  }
  const_reference operator [](size_type i) const{
    return storage[i];
  }
  size_type size(){
    return N;
  }
  reference front(){
    return storage[0];
  }
  const_reference front() const{
    return storage[0];
  }

  reference back(){
    return storage[N-1];
  }
  const_reference back() const{
    return storage[N-1];
  }

  void fill(T const &u){
    for(size_t i= 0 ; i!=N ; ++i){
      storage[i] = u;
    }
  }
  iterator begin(){
    return array_iterator(*this, 0);
  }
  iterator end(){
    return array_iterator(*this, N);
  }
};
template <typename Container>
void println(Container const &c){
  for(size_t i=0 ; i!=c.size() ; i++){
    cout << c[i] << endl;
  }
}
struct S{
  int data;
  int & get(){
    return data;
  }
  int const & get() const{
    return data;
  }
};*/
int main(){
  int H,W; cin>>H>>W;
  string s[H];
  rep(i,0,H){
    cin>>s[i];
  }
  int cnt = 0;
  rep(i,0,H)rep(j,0,W){
    if(s[i][j]=='#') cnt++;
  }
  string ans = "Impossible";
  if(cnt==H+W-1) ans = "Possible";
  cout<<ans<<endl;
  return 0;
}
