#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.first<<","<<p.second<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}
#else
#define dbg(...) {}
#endif

const long INF = LLONG_MAX / 3;

template<typename T>
class SegTree {
private:
  int n;
  vector<T> segMin, segAdd;
  void _add(int a, int b, T x, int k, int l, int r){
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){ segAdd[k]+=x; return; }
    int cl = k*2+1, cr = k*2+2;
    _add(a,b,x,cl,l,(l+r)/2);
    _add(a,b,x,cr,(l+r)/2,r);
    segMin[k] = min(segMin[cl]+segAdd[cl], segMin[cr]+segAdd[cr]);
  }
  T _min(int a, int b, int k, int l, int r) const {
    if(r<=a || b<=l) return INF;
    if(a<=l && r<=b) return segMin[k]+segAdd[k];
    return min(_min(a,b,k*2+1,l,(l+r)/2), _min(a,b,k*2+2,(l+r)/2,r)) + segAdd[k];
  }
public:
  SegTree(){}
  SegTree(int n_){
    n=1;
    while(n<n_) n*=2;
    segMin.resize(2*n-1, 0);
    segAdd.resize(2*n-1, 0);
  }
  SegTree(const vector<T> &v){
    int n_ = v.size();
    n=1;
    while(n<n_) n*=2;
    segMin.resize(2*n-1);
    segAdd.resize(2*n-1, 0);
    rep(i,n_) segMin[n+i-1] = v[i];
    for(int i=n-2; i>=0; i--) segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
  }
  inline void add(int a, int b, T x){ _add(a,b,x,0,0,n); } // add x in [a,b)
  inline T getMin(int a, int b) const { return _min(a,b,0,0,n); } // range min in [a,b)
};


int main(){
  int n,m;
  cin>>n>>m;

  vector<vector<pair<int,int>>> v(n); // <start, value>
  rep(i,m){
    int l,r,a;
    cin>>l>>r>>a;
    l--;r--;
    v[r].push_back({l,a});
  }

  SegTree<long> st(n);
  rep(i,n){
    st.add(i, i+1, min(0L, st.getMin(0,i)));
    for(auto &p : v[i]){
      st.add(p.first, i+1, -p.second);
    }
  }

  cout << max(0L, -st.getMin(0,n)) << endl;

  return 0;
}
