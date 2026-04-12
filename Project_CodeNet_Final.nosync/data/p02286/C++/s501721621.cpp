#define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_a_genius = 0; ngtkana_is_a_genius < int(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (int i = int(begin); (i) < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {};
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

unsigned long xor128() {
  static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
  unsigned long t=(x^(x<<11));
  x=y; y=z; z=w;
  return ( w=(w^(w>>19))^(t^(t>>8)) );
}

using key_type = std::int32_t;
using result_type = std::int32_t;
using priority_type = std::int32_t;

struct node_type {
  key_type key;
  priority_type p;
  node_type * ch[2];
  node_type(key_type key, priority_type p)
    : key(key), p(p)
    {
      ch[0] = ch[1] = nullptr;
    }
};

void validate(node_type * t) {
  if (!t) return;
  if (t->ch[0]) {
    assert(t->ch[0]->key < t->key);
    assert(t->ch[0]->p < t->p);
  }
  if (t->ch[1]) {
    assert(t->ch[1]->key > t->key);
    assert(t->ch[1]->p < t->p);
  }
}

node_type * top = nullptr;

node_type * rotate(node_type * t, bool b) {
  node_type * s = t->ch[1-b];
  t->ch[1-b] = s->ch[b];
  s->ch[b] = t;
  return s;
}

bool find(node_type * t, key_type key) {
  return t && (key == t->key || find(t->ch[!(key < t->key)], key));
}

node_type * insert(node_type * t, key_type key, priority_type p) {
  validate(t);
  if (!t) return ::new node_type(key, p);
  else if (key == t->key) return t;
  bool b = !(key < t->key);
  t->ch[b] = insert(t->ch[b], key, p);
  if (t->p < t->ch[b]->p) t = rotate(t, 1-b);
  return t;
}

node_type * erase(node_type * t, key_type key) {
  if (!t) return nullptr;
  if (key == t->key) {
    if (!t->ch[0] && !t->ch[1]) {
      delete t;
      return nullptr;
    }
    t = rotate(t, !t->ch[1] || (t->ch[0] && t->ch[0]->p > t->ch[1]->p));
    t = erase(t, key);
  } else {
    bool b = !(key < t->key);
    t->ch[b] = erase(t->ch[b], key);
  }
  return t;
}

void print() {
  std::vector< key_type > mid;
  std::vector< key_type > pre;
  auto dfs = [&] (auto&& dfs, node_type * t) -> void {
    if (!t) return;
    pre.emplace_back(t->key);
    dfs(dfs, t->ch[0]);
    mid.emplace_back(t->key);
    dfs(dfs, t->ch[1]);
  };
  dfs(dfs, top);
  for (auto x : mid) std::cout << " " << x;
  std::cout << std::endl;
  for (auto x : pre) std::cout << " " << x;
  std::cout << std::endl;
}

auto collect() {
  std::vector< key_type > mid;
  auto dfs = [&] (auto&& dfs, node_type * t) -> void {
    validate(t);
    if (!t) return;
    dfs(dfs, t->ch[0]);
    mid.emplace_back(t->key);
    dfs(dfs, t->ch[1]);
  };
  dfs(dfs, top);
  return mid;
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int q; std::cin >> q;
  loop(q) {
    std::string s; std::cin >> s;
    debug(s);
    switch(s.front()) {
      case 'i': {
        int x, p; std::cin >> x >> p;
        debug(s,x,p);
        top = insert(top, x, p);
        break;
      }
      case 'f': {
        int x; std::cin >> x;
        bool ans = find(top, x);
        std::cout << (ans ? "yes" : "no") << std::endl;
        break;
      }
      case 'd': {
        int x; std::cin >> x;
        top = erase(top, x);
        break;
      }
      case 'p': {
        print();
        break;
      }
    }
    debug(collect());
  }
  return 0;
}
