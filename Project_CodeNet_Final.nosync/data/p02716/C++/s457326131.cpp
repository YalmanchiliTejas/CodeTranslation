#include <iostream>
#include <cstdlib>

#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "sys/time.h"
using namespace std;
#define HERE (cerr << "LINE: " << __LINE__ << " " << __FUNCTION__ << endl)

#define DBG(x) cerr << #x << ": " << x << endl

struct timeval timer_begin, timer_end;
uint64_t tsc_begin;
double sec_per_count = 1.0 / 2.7e9;
int timer_called;
inline uint64_t get_time_64() {
  uint32_t lo, hi;
  asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
  return (((uint64_t)hi << 32) | lo);
}

inline void timer_start() 
{
  timer_called++;
  gettimeofday(&timer_begin, NULL);
  tsc_begin = get_time_64();
}     
inline double timer_now() 
{
  if (sec_per_count < 0) {
    timer_called++;
    gettimeofday(&timer_end, NULL);         
    double duration = timer_end.tv_sec - timer_begin.tv_sec +
      (timer_end.tv_usec - timer_begin.tv_usec)/1000000.0;
    uint64_t tsc_duration = get_time_64() - tsc_begin;
    sec_per_count = duration / tsc_duration;
    DBG(1/sec_per_count);
  }
  return (get_time_64() - tsc_begin) * sec_per_count;
}
void timer_stat() {
  DBG(1/sec_per_count);
  {
    timer_called++;
    gettimeofday(&timer_end, NULL);         
    double duration = timer_end.tv_sec - timer_begin.tv_sec +
      (timer_end.tv_usec - timer_begin.tv_usec)/1000000.0;
    uint64_t tsc_duration = get_time_64() - tsc_begin;

    DBG(duration);
    DBG(tsc_duration);
    DBG(tsc_duration / duration);
  }
}

#ifdef LOCAL
template<class T>
const T& clamp(const T& v,const T& lo,const T& hi) {
  return (v < lo) ? lo : (v > hi) ? hi : v;
}
#endif
template<typename T>
void assign_min_max(T& min,T& max,const T& x) {
  if (x < min)
    min = x;
  if (x > max)
    max = x;
}
unsigned int hash_function(unsigned long p) {
  // xor32()
  p ^= p<<7;
  p ^= p>>1;
  p ^= p<<25;
  unsigned int c = __builtin_popcount(p);
  return p<<c | p>>(32-c);
}
uint64_t hash_function64(uint64_t p) {
  // xor64()
  p ^= p<<16;
  p ^= p>>7;
  p ^= p<<39;
  uint64_t c = __builtin_popcount(p);
  return p<<c | p>>(64-c);
}  

struct xor128_t {
  uint64_t x, y, z, w;

  xor128_t(int seed=0) : x(123456789^seed) , y(362436069), z(521288629), w(88675123) {
    for (int i=0; i<48; i++)
      get();
  }

  void init(int seed) {
    x = 123456789^seed;
    y = 362436069;
    z = 521288629;
    w = 88675123;

    for (int i=0; i<48; i++)
      get();
  }

  inline uint64_t get() {
    uint64_t t=(x^(x<<11)); x=y; y=z; z=w;
    return (w=(w^(w>>19))^(t^(t>>8)));
  }

  inline uint64_t get(unsigned int sz) {
    if (sz <= 1)
      return 0;

    uint64_t x;
    const uint64_t mask = (1<<(ilogb(sz-1)+1)) - 1;
    //cout << sz << " " << mask << endl;
    assert(mask >= (sz-1) && mask < 2*sz-1);
    do {
      x = get() & mask;
    } while (x >= sz);

    return x;
  }

  inline int64_t get(int beg,int end) {
    return get(end-beg) + beg;
  }

  double get_double() {
    static const double double_factor = 1.0 / (1.0 + 0xffffffffffffffffuLL);
    return get() * double_factor;
  }

  double get_norm() {
    double a = get_double();
    double b = get_double();

    return sqrt(-2*log(a)) * cos(2*M_PI*b);
  }

  double get_gamma(double a) {
    if (a < 1.0) {
      return get_gamma(1+a) * pow(get_double(), 1/a);
    }
    
    double d = a - 1/3.0;
    double c = 1/sqrt(9.0 * d);

    while (true) {
      double x = get_norm();
      double uni = 1 - get_double();
      double v = (1.0+c*x)*(1.0+c*x)*(1.0+c*x);
      if (v > 0 && log(uni) < 0.5 * x*x + d - d*v + d*log(v))
	return d*v;
    }
  }

  template<typename T> void shuffle(vector<T>& v,int partial=-1) {
    int sz = v.size();
    if (partial < 0 || partial > sz)
      partial = sz;

    for (int i=0; i<partial; i++) {
      swap(v[i], v[i + get(sz-i)]);
    }
  }
  
  template<typename T> T sample(const vector<T>& v) {
    assert(!v.empty());
    return v[get(v.size())];
  }
};

// Van der Corput sequence
double vdc(int i,int base) {
  double result = 0;
  double f = 1;

  while (i > 0) {
    f /= base;
    result += f * (i%base);
    i = i/base;
  }

  return result;
}

struct uf_t {
  vector <int16_t> parent;

  void clear() {
    parent.clear();
  }

  void add(int elm) {
    if (elm >= parent.size()) 
      parent.resize(elm+1, -1);
  }

  void merge(int a,int b) {
    add(a);
    add(b);

    int ia = a;
    int ib = b;

    if ((ia^ib)&1) swap(ia, ib);  // ok?
      
    int ra = root(ia);
    int rb = root(ib);

    if (ra != rb) {
      parent[ra] += parent[rb];
      parent[rb] = ra;
    }
  }

  int size(int elm) {
    return -parent[root(elm)];
  }

  int id(int elm) {
    return root(elm);
  }

  int root(int ia) {
    add(ia);
    return (parent[ia] < 0) ? ia : (parent[ia] = root(parent[ia]));
  }
};

struct reusable_set_t {
  typedef uint8_t mark_t;
  mark_t mark;
  vector<mark_t> v;
  reusable_set_t() {}
  reusable_set_t(int n) : v(n), mark(1) {}

  void insert(int x) { v[x] = mark; }
  void erase(int x) { v[x] = mark-1; }
  int count(int x) const { return (v[x] == mark); }
  void clear() {
    mark++;
    if (mark == 0) {
      fill(v.begin(), v.end(), 0);
      mark ++;
    }
  }
};

struct sa_t {
  double ini, fin, inv_T, progress;
  int num_call, num_accept, num_better;
  xor128_t rng;
  sa_t() {}
  sa_t(double ini, double fin) : ini(ini), fin(fin), num_accept(0), num_call(0), num_better(0) {
    set_progress(0);
  }

  void set_progress(double x) {
    progress = clamp(x, 0.0, 1.0);
    inv_T = 1 / (ini * pow(fin/ini, progress));
  }

  bool acceptable(double x) {
    //bool result = (x > 0) || rng.get_double() < exp(x*inv_T);
    //bool result = (x > 0) || log(1-rng.get_double()) < x*inv_T;
    double z = x*inv_T;
    bool result = (x > 0) || (z > -12 && log(1-rng.get_double()) < z);

    //num_call ++;
    //num_accept += result;
    //num_better += (x > 0);

    return result;
  }

  void show_log() const {
    cerr << "better/accept/call: "
	 << num_better
	 << "/" << num_accept
	 << "/" << num_call 
	 << " " << (double)num_accept/num_call << endl;
  }
};


template <typename T>
struct pool_t {
  vector<T> v;
  int N;

  pool_t(int sz=0) : v(sz), N(0) {}

  void clear() { N = 0; }
  T& next() {
    N++;
    while (N >= v.size())
      v.resize(v.size()*11/10 + 1);
    return v[N-1];
  }

  typename vector<T>::iterator begin() { return v.begin(); }
  typename vector<T>::iterator end() { return v.begin()+N; }
  T& operator[](int i) { return v[i]; }
  size_t size() const { return N; }
  void resize(int sz) { assert(sz <= N); N = sz; }
  void swap(pool_t<T>& pl) {
    v.swap(pl.v);
    std::swap(N, pl.N);
  }
};

template <typename Score_t,typename Item_t,typename HashFunc_t>
struct best_k_t {
  vector<pair<Score_t,int>> v;
  vector<Item_t> items;
  HashFunc_t hashfunc;
  set<uint32_t> used;
  bool never_push;

  best_k_t() : never_push(false) {}

  void push_force(const Score_t sc,const Item_t& e) {
    int id = items.size();
    items.push_back(e);

    int n = v.size();
    v.push_back(pair<Score_t,int>(sc,id));

    int m = (n+1)/2 - 1;
    while (n > 0 && v[n] < v[m]) {
      swap(v[n], v[m]);
      n = m;
      m = (n+1)/2 - 1;
    }
  }

  bool push(const Score_t sc,const Item_t& e,int w) {
    assert(!never_push);
    if (v.size() < w) {
      auto h = hashfunc(e);
      if (!used.count(h)) {
	used.insert(h);
	push_force(sc, e);
	return true;
      } else {
	return false;
      }
    } else if (sc > v[0].first) {
      auto h = hashfunc(e);
      if (!used.count(h)) {
	int id = v[0].second;
	v[0].first = sc;
	items[id] = e;
	used.insert(h);
	rebuild();
	return true;
      } else {
	return false;
      }
    }
    return false;
  }

  bool match(const Score_t sc,int w) {
    return (v.size() < w || sc > v[0].first);
  }

  void rebuild() {
    int n = 0;
    while (true) {
      int L = (n+1)*2 - 1;
      int R = L+1;

      if (L >= v.size()) 
	break;

      int m = (R >= v.size() || v[L] < v[R]) ? L : R;

      if (v[m] < v[n]) {
	swap(v[m], v[n]);
	n = m;
      } else {
	break;
      }
    }
  }

  Item_t pop() {
    // fix me
    never_push = true;
    
    int id = v[0].second;
    Item_t ret = items[id];

    v[0] = v.back();
    v.pop_back();

    rebuild();

    return ret;
  }
  Item_t top() { return v[0].second; }

  Item_t best() const {
    int best_i = 0;
    for (int i=0; i<v.size(); i++) {
      if (v[i] < v[best_i])
	best_i = i;
    }
    return items[v[best_i].second];
  }

  void clear() { v.clear(); }
  bool empty() const { return v.empty(); }
  int size() const { return v.size(); }
};

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
    os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " ]"; 
  return os; 
}
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{ ";
  for(typename set<T>::const_iterator it=v.begin(); it!=v.end(); ++it) {
    if (it != v.begin())
      os << ", ";
    os << *it; 
  }
  os << " }"; 
  return os; 
}
template<typename T1,typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& v) {
  os << "[ " << v.first << ", " << v.second << "]";
  return os; 
}

#ifdef LOCAL
double TIME_LIMIT_FACTOR = 0.55;
#else
double TIME_LIMIT_FACTOR = 1.0;
#endif
double TIME_LIMIT = TIME_LIMIT_FACTOR * 10.0;

/* insert here */
int64_t solve(int N,const vector<int64_t>& A) {
  vector<int64_t> memo(3*N);

  int skip = (N%2 == 0) ? 1 : 2;
  for (int i=0; i<=skip; i++) {
    memo[i*3+i] = A[i];
    for (int j=0; j<=skip; j++) {
      //memo[i*3+i] = max(memo[i*3+i], A[j]);
    }
  }
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<=skip; j++) {
      if (i <= j)
        continue;
      if ((i+j)&1)
        continue;

      memo[i*3+j] = memo[(i-2)*3+j];
      for (int k=0; k<=j; k++) {
        memo[i*3+j] = max(memo[i*3+j], memo[(i-2-k)*3+(j-k)]);
      }
      memo[i*3+j] += A[i];
    }
  }

#ifdef LOCAL
  if (N < 20) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<=skip; j++)
        cerr << memo[i*3+j] << "\t";
      cerr << endl;
    }
  }
#endif

  auto mx = memo[(N-1-skip)*3];
  for (int j=0; j<=skip; j++) {
    mx = max(mx, memo[(N-1-skip+j)*3+j]);
  }
  
  return mx;
}


int main() {
  int N;
  cin >> N; cin.ignore();
  vector<int64_t> A(N);
  for (int i=0; i<N; i++)
    cin >> A[i];

  auto ret = solve(N, A);
  cout << ret << endl;

  return 0;
}
  
