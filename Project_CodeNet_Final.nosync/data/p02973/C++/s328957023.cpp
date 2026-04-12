#include <bits/stdc++.h>
#define LLI long long int
#define FOR(v, a, b) for(LLI v = (a); v < (b); ++v)
#define FORE(v, a, b) for(LLI v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(LLI v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define popcount __builtin_popcount
#define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())
#define bit(i) (1LL<<(i))

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(...) ((void)0)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T, typename U> istream& operator>>(istream &is, pair<T,U> &p){is >> p.first >> p.second; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}

class UnionFind{
  vector<int> parent, depth, size;
  int count;
public:
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    iota(ALL(parent),0);
  }
  int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  bool is_same(int i, int j){return get_root(i) == get_root(j);}
  int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }
  int get_size(int i){return size[get_root(i)];}
  int count_group(){return count;}
};

/**
 * @details eは単位元
 */
template <typename T> class SegmentTree{
private:
  int size;
  vector<T> vec;
  T e;
  function<T(T,T)> f, upd;
  
  inline T aux(int x, int y, int i, int l, int r){
    if(r<=x || y<=l) return e;
    else if(x<=l && r<=y) return vec[i];
    else return f(aux(x,y,i*2+1,l,(l+r)/2), aux(x,y,i*2+2,(l+r)/2,r));
  };

public:
  SegmentTree(int n, const T &e, const function<T(T,T)> &f, const function<T(T,T)> &upd): e(e), f(f), upd(upd){
    size = 1;
    while(size < n) size *= 2;
    size = size*2-1;
    vec = vector<T>(size, e);
  }

  inline void update(int i, const T &x){
    int j = i+(size+1)/2-1;
    vec[j] = upd(vec[j], x);
    --j;
    while(j>=0){
      vec[j/2] = f(vec[(j/2)*2+1], vec[(j/2)*2+2]);
      (j /= 2) -= 1;
    }
  }

  inline T get(int x, int y){ // [x,y)
    return aux(x,y,0,0,(size+1)/2);
  }
};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  while(cin >> n){
    vector<int> a(n); cin >> a;

    vector<int> b(a);
    sort(ALL(b));
    UNIQ(b);

    REP(i,n) a[i] = lower_bound(ALL(b), a[i]) - b.begin();
    

    vector<bool> check(n);
    UnionFind uf(n);

    vector<vector<int>> poss(n); 
    SegmentTree<int> seg(n, INT_MAX, [](int x, int y){return min(x,y);}, [](int x, int y){return y;});
    
    
    REP(i,n){
      poss[a[i]].push_back(i);
    }

    REP(i,n){
      sort(RALL(poss[i]));
      if(poss[i].size()) seg.update(i,poss[i].back());
    }

    REP(i,n){
      if(check[i]) continue;
      check[i] = true;

      //      cerr << i << endl;

      poss[a[i]].pop_back();

      if(poss[a[i]].empty()) seg.update(a[i], INT_MAX);
      else seg.update(a[i], poss[a[i]].back());

      int j = i;
      while(1){
        int p = seg.get(a[j]+1,n);
        if(p == INT_MAX) break;

        poss[a[p]].pop_back();

        if(poss[a[p]].empty()) seg.update(a[p], INT_MAX);
        else seg.update(a[p], poss[a[p]].back());

        uf.merge(j,p);
        j = p;
        //cerr << j << endl;
        check[j] = true;
      }
      //cerr << endl;
    }

    int ans = uf.count_group();

    cout << ans << endl;
  }
  
  return 0;
}
