#line 0 "cmacro.cpp"

#include <bits/stdc++.h>
using namespace std;

#define in ,
#define esc_paren(...) __VA_ARGS__
#define pp_empty(...)
#define pp_cat_i(x, y) x ## y
#define pp_cat(x, y) pp_cat_i(x, y)

#define pp_inc0 1
#define pp_inc1 2
#define pp_inc2 3
#define pp_inc3 4
#define pp_inc4 5
#define pp_inc5 6
#define pp_inc6 7
#define pp_inc7 8
#define pp_inc8 9
#define pp_inc(i) pp_cat(pp_inc, i)

#define pp_arg10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
#define pp_has_comma(...) pp_arg10(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 0)
#define pp_trigger_paren(...) ,
#define pp_is_empty(...) \
  pp_is_empty1( \
      pp_has_comma(__VA_ARGS__), \
      pp_has_comma(pp_trigger_paren __VA_ARGS__), \
      pp_has_comma(__VA_ARGS__()), \
      pp_has_comma(pp_trigger_paren __VA_ARGS__()) \
      ) 
#define pp_paste5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define pp_is_empty1(_0, _1, _2, _3) pp_has_comma(pp_paste5(pp_is_empty_case_, _0, _1, _2, _3))
#define pp_is_empty_case_0001 ,

#define pp_is_one(...) pp_is_one_(__VA_ARGS__, pp_one_seq)
#define pp_is_one_(...) pp_is_one_n(__VA_ARGS__)
#define pp_is_one_n(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10, N, ...) N
#define pp_one_seq 0,0,0,0,0,0,0,0,0,1,0

#define pp_narg(...) \
         pp_narg_(__VA_ARGS__, pp_narg_seq)
#define pp_narg_(...) \
         pp_narg_n(__VA_ARGS__)
#define pp_narg_n( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,n,...) n
#define pp_narg_seq \
         63,62,61,60, \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
          9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define pp_if_0(x, y) y
#define pp_if_1(x, y) x
#define pp_if(cond, x, y) pp_cat(pp_if_, cond)(x, y)

#define pp_foreach_i9(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i8(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i7(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i6(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i5(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i4(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i3(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i2(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i1(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i0(i, f, x, ...) f(x) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach_i(i, f, ...) pp_if(pp_is_empty(__VA_ARGS__), pp_empty, pp_cat(pp_foreach_i, i))(pp_inc(i), f, __VA_ARGS__)
#define pp_foreach(f, ...) pp_foreach_i(0, f, __VA_ARGS__)


typedef long long ll;
#define down_queue(x) priority_queue<x>
#define up_queue(x) priority_queue<x, vector<x>, greater<x>>
#define all(x) x.begin(), x.end()
#define split_str(str, sp_word) istringstream stream(str); string res; for(int cnt = 0; getline(stream,res,sp_word); cnt++)
#define digit(x) ((int)log10((double)(x)) + 1)
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vec_cpy(to,from) copy(all(to),back_inserter(from))
#define ary_cpy(to,from) memcpy(to, from, sizeof(from))
#define MOD 1000000007
#define INF 999999999


template <typename T>
struct RepIterator {
  T i;
  RepIterator() : i(0) {}
  RepIterator(T n) : i(n) {}
  bool operator ==(const RepIterator<T>& rhs) { return i == rhs.i; }
  bool operator !=(const RepIterator<T>& rhs) { return i != rhs.i; }
  T operator *() { return i; }
  RepIterator<T> operator ++() {i++; return *this; };
};
template <typename T>
struct RepLoop {
  T i;
  RepLoop(T n) : i(n) {}
  RepIterator<T> begin() { return RepIterator<T>(); }
  RepIterator<T> end() { return RepIterator<T>(i); }
};

template <typename T>
struct rep_range {
  static T range(T v) {
    return v;
  }
};

#define def_range(t) \
  template <> \
  struct rep_range<t> { \
    static RepLoop<t> range(t n) { \
      return RepLoop<t>(n); \
    } \
  };
def_range(int);
def_range(size_t);

#define rep(...) rep1(rep2, (__VA_ARGS__))
#define rep1(X, A) X A
#define rep2(i, ...) pp_if(pp_is_one(__VA_ARGS__), rep_len1(i, __VA_ARGS__), rep3(i, __VA_ARGS__))
#define rep_len1(i, end, ...) for (auto i : rep_range<decltype(end)>::range(end))
#define rep3(i, iter, ...) rep4(rep5, (iter, i, esc_paren __VA_ARGS__))
#define rep4(X, A) X A
#define rep5(iter, ...) iter(__VA_ARGS__)

#define up up_iter ,
#define up_iter3(i, start, end) for (auto i = start; i < end; i++)
#define up_iter4(i, start, end, up) for (auto i = start; i < end; i += up)
#define up_iter(...) pp_cat(up_iter, pp_narg(__VA_ARGS__))(__VA_ARGS__)
#define down down_iter ,
#define down_iter2(i, end) for(auto i = end-1; i >= 0; i--)
#define down_iter3(i, start, end) for (auto i = end-1; i >= start; i--)
#define down_iter4(i, start, end, down) for (auto i = end-1; i >= start; i -= down)
#define down_iter(...) pp_cat(down_iter, pp_narg(__VA_ARGS__))(__VA_ARGS__)


#define pp_init2(cnt, body) struct _InitStruct ## cnt { _InitStruct ## cnt() { body } } _initstruct ## cnt;
#define pp_init1(f, cnt, body) f(cnt, body)
#define pp_init(body) pp_init1(pp_init2, __COUNTER__, body)

#define init_array(arr, N, val) pp_init(rep (i in N) { arr[i] = val; })
#define iota_array(arr, N, start) pp_init(rep (i in N) { arr[i] = start + i; })


#define debug_var_elem(v) << #v << "=" << v << " "
#ifdef DEBUG
#define debug_echo(e) cout << "L" << __LINE__ << ": " << e << endl
#define debug_var(...) cout << "L" << __LINE__ << ": " pp_foreach(debug_var_elem, __VA_ARGS__) << endl
#define debug_time2(i, e) auto start ## i = clock(); e; auto end ## i = clock(); cout << "L" << __LINE__ << ": " << (double)(end ## i - start ## i) << "ms" << endl;
#define debug_time1(f, i, e) f(i, e)
#define debug_time(e) debug_time1(debug_time2, __COUNTER__, e)
#else
#define debug_echo(e)
#define debug_var(...)
#define debug_time(e) e;
#endif


#define pp_gen_field(list) pp_gen_field1 list
#define pp_gen_field1(name, val) decltype(val) name;
#define pp_gen_init(list) pp_gen_init1 list
#define pp_gen_init1(name, val) ,val
#define pp_gen_find_set_wrap(ufnodename) ufnodename pp_gen_find_set
#define pp_gen_find_set(list) pp_gen_find_set1 list
#define pp_gen_find_set1(name, val) \
  find_set_ ## name(int x, decltype(val) v) { \
    if (nodes[x].parent == x) { \
      nodes[x].name = v; \
      return nodes[x]; \
    } else { \
      return nodes[x] = find_set_ ## name(nodes[x].parent, v); \
    } \
  }
#define pp_gen_unite_set(list) pp_gen_unite_set1 list
#define pp_gen_unite_set1(name, val) \
  if (nodes[x].name == val) { \
    find_set_ ## name(x, find(y).name); \
  } \
  if (nodes[y].name == val) { \
    find_set_ ## name(y, find(x).name); \
  }

#define def_unionfind(ufname, ufnodename, ...) \
  struct ufnodename { \
    int parent; \
    pp_foreach(pp_gen_field, __VA_ARGS__) \
  }; \
  struct ufname { \
    vector<ufnodename> nodes; \
    vector<int> rank; \
    ufname(int n) : nodes(n+1), rank(n+1) { \
      rep (i in n) { \
        nodes[i] = ufnodename{i pp_foreach(pp_gen_init, __VA_ARGS__)}; \
        rank[i] = 0; \
      } \
    } \
    ufnodename find(int x) { \
      if (nodes[x].parent == x) { \
        return nodes[x]; \
      } else { \
        return nodes[x] = find(nodes[x].parent); \
      } \
    } \
    pp_foreach(pp_gen_find_set_wrap(ufnodename), __VA_ARGS__) \
    void unite(int x, int y) { \
      x = find(x).parent; \
      y = find(y).parent; \
      if (x == y) return; \
      if (rank[x] < rank[y]) { \
        pp_foreach(pp_gen_unite_set, __VA_ARGS__); \
        nodes[x].parent = y; \
      } else { \
        pp_foreach(pp_gen_unite_set, __VA_ARGS__); \
        nodes[y].parent = x; \
        if (rank[x] == rank[y]) rank[x]++; \
      } \
    } \
    bool same(int x, int y) { \
      return find(x).parent == find(y).parent; \
    } \
  }


ll gcd(ll a,ll b){while(b){ll tmp = a % b;a = b;b = tmp;}return a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
bool is_prime(ll n){switch(n){case 0:case 1: return false;case 2: return true;}if(n % 2 == 0) return false;for(ll i=3;i * i <= n; i += 2)if(n%i == 0) return false;return true;}

#define def_varargs(name, f) \
  template<typename First> \
  inline First name(First first) { return first; } \
  template<typename First, typename... Rest> \
  inline First name(First first, Rest... rest) { return f(first, name(rest...)); }

#line 1 "procon.cpp"

bool player[1001];

void nextplayer(int m, int& curp) {
  while (true) {
    curp++;
    if (curp > m) {
      curp = 1;
    }
    if (player[curp]) {
      return;
    }
  }
}

string itos(int i) {
  ostringstream s;
  s << i;
  return s.str();
}

string fizzbuzz(int i) {
  if (i % 15 == 0) return "FizzBuzz";
  if (i % 5 == 0) return "Buzz";
  if (i % 3 == 0) return "Fizz";
  return itos(i);
}

int main() {
  int m, n;
  while (cin >> m >> n && m && n) {
    rep (i in m+1) player[i] = true;
    int pcnt = m;
    int curp = 1;
    bool is_end = false;
    rep (i in n) {
      string s; cin >> s;
      if (is_end) continue;
      if (fizzbuzz(i+1) != s) {
        pcnt--;
        player[curp] = false;
      }
      if (pcnt == 1) {
        is_end = true;
        continue;
      };
      nextplayer(m, curp);
    }
    bool isfirst = true;
    rep (i in up(1, m+1)) {
      if (isfirst && player[i]) {
        cout << i;
        isfirst = false;
      } else if (player[i]) {
        cout << " " << i;
      }
    }
    cout << endl;
  }
}