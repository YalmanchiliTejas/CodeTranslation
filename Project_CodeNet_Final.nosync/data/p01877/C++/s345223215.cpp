#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

// quoted from beet-aizu
template <typename T,typename E, typename F, typename G, typename H>
struct LazySegmentTree{
    //using F = function<T(T,T)>;
    //using G = function<T(T,E)>;
    //using H = function<E(E,E)>;
    int n,height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> dat;
    vector<E> laz;
    LazySegmentTree(F f,G g,H h,T ti,E ei):
        f(f),g(g),h(h),ti(ti),ei(ei){}

    void init(int n_){
        n=1;height=0;
        while(n<n_) n<<=1,height++;
        dat.assign(2*n,ti);
        laz.assign(2*n,ei);
    }
    void build(const vector<T> &v){
        int n_=v.size();
        init(n_);
        for(int i=0;i<n_;i++) dat[n+i]=v[i];
        for(int i=n-1;i;i--)
            dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
    }
    inline T reflect(int k){
        return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
    }
    inline void eval(int k){
        if(laz[k]==ei) return;
        laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
        laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=ei;
    }
    inline void thrust(int k){
        for(int i=height;i;i--) eval(k>>i);
    }
    inline void recalc(int k){    
        while(k>>=1)
            dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
    }
    void update(int a,int b,E x){
        thrust(a+=n);
        thrust(b+=n-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) laz[l]=h(laz[l],x),l++;
            if(r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int a,T x){
        thrust(a+=n);
        dat[a]=x;laz[a]=ei;
        recalc(a);
    }
    T query(int a,int b){
        thrust(a+=n);
        thrust(b+=n-1);
        T vl=ti,vr=ti;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
            if(l&1) vl=f(vl,reflect(l++));
            if(r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
};

/* 
 *    [考えるべきこと]
 *    区間をマージしてから作用素を作用させても、作用素を作用させてから区間をマージするのと結果が同じ
 *    複数の作用素をマージして一度に作用させられること
 *    作用素を伝搬し終わっているのかの判定に必要（まあこれは満たされていなくても最悪どうにかなる）
 *    O(N) とかだと困る（setのマージとか）
 *    区間の長さに比例して作用が変わるときは，practice/RSRA や Library-Checher の RangeAffineRangeSum を参照する
 * 
 */

/**  テンプレ
int main(){
  using T = ***;  // type T
  using E = ***;  // type E
  auto f = [](T a, T b){ // return type T value
    return ***;
  };
  auto g = [](T a, E b){ // return type T value
    return ***;
  };
  auto h = [](E a, E b){ // return type E value
    return ***;
  };
  T ti = ***;  // identity element
  E ei = ***;  // identity element
  LazySegmentTree<T, E, decltype(f), decltype(g), decltype(h)> sg(f, g, h, ti, ei);  // don't change
  sg.build(***);
}
**/


#define int long long


signed main() {
  
  int n; cin >> n;
  vector<lint> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<lint> dat(n / 2);
  for (int i = 0; i < n / 2; i++) {
    dat[i] = s[i] - s[n - i - 1];
  }

  auto f1 = [](int a, int b){ return min(a, b); };
  auto g1 = [](int a, int b){ return a + b; };
  auto h1 = [](int a, int b){ return a + b; };
  LazySegmentTree<int, int, decltype(f1), decltype(g1), decltype(h1)> sgmin(f1, g1, h1, INT_MAX, 0);
  sgmin.build(dat);

  auto f2 = [](int a, int b){ return max(a, b); };
  auto g2 = [](int a, int b){ return a + b; };
  auto h2 = [](int a, int b){ return a + b; };
  LazySegmentTree<int, int, decltype(f2), decltype(g2), decltype(h2)> sgmax(f2, g2, h2, -INT_MAX, 0);
  sgmax.build(dat);
  
  /*cerr << "min" << endl;
  for (int i = 0; i < n / 2; i++) {
    cerr << sgmin.query(i, i + 1) << " ";
  }
  cerr << endl;
  cerr << "max" << endl;
  for (int i = 0; i < n / 2; i++) {
    cerr << sgmax.query(i, i + 1) << " ";
  }
  cerr << endl;
  */

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r, x; cin >> l >> r >> x;
    l--;
    r--;
    
    // [0, n / 2)
    // [n / 2, n)
    if (r < n / 2) {
      sgmin.update(l, r + 1, x);
      sgmax.update(l, r + 1, x);
    } else if (l >= n / 2) {
      int ll = n - r - 1;
      int rr = n - l - 1;

      sgmin.update(ll, rr + 1, -x);
      sgmax.update(ll, rr + 1, -x);
    } else {
      // cerr << l << " " << n / 2 << " " << x << endl;
      sgmin.update(l, n / 2, x);
      sgmax.update(l, n / 2, x);
      
      int ll = n - r - 1;
      // cerr << ll << " " << n / 2 << " " << -x << endl;
      sgmin.update(ll, n / 2, -x);
      sgmax.update(ll, n / 2, -x);
    }

    // cerr << "min" << endl;
    /*
    for (int i = 0; i < n / 2; i++) {
      cerr << sgmin.query(i, i + 1) << " ";
    }
    cerr << endl;
    cerr << "max" << endl;
    for (int i = 0; i < n / 2; i++) {
      cerr << sgmax.query(i, i + 1) << " ";
    }
    cerr << endl;


    // 左 - 右をしているので
    cerr << sgmin.query(0, n / 2) << " " << sgmax.query(0, n / 2) << endl;

    */
    cout << (sgmin.query(0, n / 2) == 0 and sgmax.query(0, n / 2) == 0) << endl;
  }

  return 0;
}

