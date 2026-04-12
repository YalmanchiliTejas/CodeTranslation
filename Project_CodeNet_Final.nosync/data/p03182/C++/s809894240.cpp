#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #define __clock__
#else
    #pragma GCC optimize("Ofast")
    // #define NDEBUG
#endif
// #define __buffer_check__
#define __precision__ 10
#define iostream_untie true
#define debug_stream std::cerr

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
#define odd(n) ((n) & 1)
#define even(n) (not __odd(n))
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)

using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using rheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> using hashset = std::unordered_set<T>;
template <class Key, class Value> using hashmap = std::unordered_map<Key, Value>;

namespace setting
{
    using namespace std::chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { debug_stream << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
    void buffer_check() { char bufc; if(std::cin >> bufc) debug_stream << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
            std::cout << std::fixed << std::setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
    #endif
    #ifdef stdout_path
            if(not freopen(stdout_path, "w", stdout))
            {
                freopen("CON", "w", stdout);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdout file.\n";
            }
            std::cout << "";
    #endif
    #ifdef stdin_path
            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                debug_stream << "\n\033[1;35mwarning\033[0m: failed to open stdin file.\n";
            }
    #endif
    #ifdef LOCAL
            debug_stream << "\n----- stderr at LOCAL -----\n\n";
            atexit(print_elapsed_time);
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #if defined(__clock__) || defined(LOCAL)
            start_time = system_clock::now();
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting
#ifdef __clock__
class
{
    std::chrono::system_clock::time_point built_pt, last_pt; int built_ln, last_ln;
    std::string built_func, last_func; bool is_built = false;
  public:
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true, last_pt = built_pt = std::chrono::system_clock::now(), last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built) last_pt = std::chrono::system_clock::now(), last_ln = crt_ln, last_func = crt_func;
        else debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built!)\n";
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            long long diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " << last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built!)\n";
        }
    }
} myclock; // unnamed class
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

namespace std
{
    // hash
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    // iostream
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std

#ifdef LOCAL
    #define dump(...)                                                              \
        debug_stream << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]\n",       \
            dump_func(#__VA_ARGS__, __VA_ARGS__)
    template <class T> void dump_func(const char *ptr, const T &x)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != '\0'; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << '\n';
    }
    template <class T, class... rest_t> void dump_func(const char *ptr, const T &x, rest_t... rest)
    {
        debug_stream << '\t';
        for(char c = *ptr; c != ','; c = *++ptr) if(c != ' ') debug_stream << c;
        debug_stream << " : " << x << ",\n"; dump_func(++ptr, rest...);
    }
#else
    #define dump(...) ((void)0)
#endif

template <class T = int> T read() { T x; std::cin >> x; return x; }
template <class iterator> void read(iterator __first, iterator __last) { for(iterator i = __first; i != __last; ++i) std::cin >> *i; }
template <class iterator> void write(iterator __first, iterator __last) { for(iterator i = __first; i != __last; std::cout << (++i == __last ? "" : " ")) std::cout << *i; }

// substitute y for x if x > y.
template <class T> inline bool sbmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool sbmax(T &x, const T &y) { return x < y ? x = y, true : false; }

// binary search on integers.
long long bin(long long __ok, long long __ng, const std::function<bool(long long)> &pred)
{
    while(std::abs(__ok - __ng) > 1)
    {
        long long mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// binary search on real numbers.
long double bin(long double __ok, long double __ng, const long double eps, const std::function<bool(long double)> &pred)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// binary search on integers(with a class member function).
template <class X, class int_t>
long long bin(long long __ok, long long __ng, bool (X::*const pred)(int_t), X *const x)
{
    while(std::abs(__ok - __ng) > 1)
    {
        long long mid{(__ok + __ng) / 2};
        ((x->*pred)(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// binary search on real numbers(with a class member function).
template <class X, class real_t>
long double bin(long double __ok, long double __ng, const long double eps, bool (X::*const pred)(real_t), X *const x)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        ((x->*pred)(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}

// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

// reset all bits.
template <class A> void reset(A &array) { memset(array, 0, sizeof(array)); }


/* The main code follows. */

using namespace std;

#ifndef LAZY_SEGMENT_TREE_HPP
#define LAZY_SEGMENT_TREE_HPP
template <class Monoid, class Actor>
class lazy_segment_tree
{
    using value_type = typename Monoid::value_type;
    using actor_value_type = typename Actor::value_type;
    Monoid *const monoid_ptr, &monoid;
    Actor *const actor_ptr, &actor;
    const size_t orig_n, ext_n;
    std::vector<value_type> data;
    std::vector<actor_value_type> lazy;
    bool *const flag;

    void eval(size_t k, size_t l, size_t r)
    {
        if(!flag[k]) return;
        actor.act(data[k], lazy[k]);
        if(r - l > 1)
        {
            actor(lazy[k << 1], lazy[k]);
            actor(lazy[k << 1 ^ 1], lazy[k]);
            flag[k << 1] = flag[k << 1 ^ 1] = true;
        }
        lazy[k] = actor.identity(), flag[k] = false;
    }

    void update(size_t a, size_t b, const actor_value_type &x, size_t k, size_t l, size_t r)
    {
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b)
        {
            actor(lazy[k], x);
            flag[k] = true;
            eval(k, l, r);
        }
        else
        {
            update(a, b, x, k << 1, l, (l + r) >> 1);
            update(a, b, x, k << 1 ^ 1, (l + r) >> 1, r);
            data[k] = monoid(data[k << 1], data[k << 1 ^ 1]);
        }
    }

    value_type fold(size_t a, size_t b, size_t k, size_t l, size_t r)
    {
        if(b <= l || r <= a) return monoid.identity();
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        return monoid(fold(a, b, k << 1, l, (l + r) >> 1), fold(a, b, k << 1 ^ 1, (l + r) >> 1, r));
    }

    void left_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                    size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx <= l || r < res) return;
        eval(k, l, r);
        if(r <= idx)
        {
            const value_type nxt = monoid(data[k], now);
            if(pred(nxt))
            {
                res = l, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            left_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
            left_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
        }
    }

    void right_bound(size_t idx, const std::function<bool(const value_type &)> &pred,
                     size_t k, size_t l, size_t r, value_type &now, size_t &res)
    {
        if(idx >= r || l > res) return;
        eval(k, l, r);
        if(l >= idx)
        {
            const value_type nxt = monoid(now, data[k]);
            if(pred(nxt))
            {
                res = r, now = nxt;
                return;
            }
        }
        if(r - l > 1)
        {
            right_bound(idx, pred, k << 1, l, (l + r) >> 1, now, res);
            right_bound(idx, pred, k << 1 ^ 1, (l + r) >> 1, r, now, res);
        }
    }

  public:
    lazy_segment_tree(size_t n) : monoid_ptr{new Monoid}, monoid{*monoid_ptr}, actor_ptr{new Actor}, actor{*actor_ptr}, orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1),
                                    data(ext_n << 1, monoid.identity()), lazy(ext_n << 1, actor.identity()), flag(new bool[ext_n << 1]) {}
    lazy_segment_tree(size_t n, Monoid &_monoid) : monoid_ptr{}, monoid{_monoid}, actor_ptr{new Actor}, actor{*actor_ptr}, orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1),
                                                    data(ext_n << 1, monoid.identity()), lazy(ext_n << 1, actor.identity()), flag(new bool[ext_n << 1]) {}
    lazy_segment_tree(size_t n, Actor &_actor) : monoid_ptr{new Monoid}, monoid{*monoid_ptr}, actor_ptr{}, actor{_actor}, orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1),
                                                data(ext_n << 1, monoid.identity()), lazy(ext_n << 1, actor.identity()), flag(new bool[ext_n << 1]) {}
    lazy_segment_tree(size_t n, Monoid &_monoid, Actor &_actor) : monoid_ptr{}, monoid{_monoid}, actor_ptr{}, actor{_actor}, orig_n{n}, ext_n(n > 1 ? 1 << (32 - __builtin_clz(n - 1)) : 1),
                                                                data(ext_n << 1, monoid.identity()), lazy(ext_n << 1, actor.identity()), flag(new bool[ext_n << 1]) {}
    ~lazy_segment_tree() { if(monoid_ptr) delete monoid_ptr; if(actor_ptr) delete actor_ptr; delete[] flag; }

    // const reference to index i.
    value_type operator[](size_t i) { return fold(i, i + 1); }

    void build(value_type *__first, value_type *__last)
    {
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n; i; --i) data[i] = monoid(data[i << 1], data[i << 1 ^ 1]);
    }

    template <class iterator>
    void build(iterator __first, iterator __last)
    {
        static_assert(std::is_same<typename std::iterator_traits<iterator>::value_type, value_type>::value, "iterator's value_type should be equal to Monoid's");
        std::copy(__first, __last, &data[ext_n]);
        for(size_t i = ext_n - 1; i; --i) data[i] = monoid(data[i << 1], data[i << 1 ^ 1]);
    }

    void init(const value_type &x)
    {
        for(size_t i = 0; i != ext_n; ++i) data[i | ext_n] = x;
        for(size_t i = ext_n - 1; i; --i) data[i] = monoid(data[i << 1], data[i << 1 ^ 1]);
    }

    void update(size_t a, const actor_value_type &x) { update(a, a + 1, x); }

    void update(size_t a, size_t b, const actor_value_type &x) { update(a, b, x, 1, 0, ext_n); }

    value_type fold(size_t a, size_t b) { return fold(a, b, 1, 0, ext_n); }

    // minimum l where range [l, idx) meets the condition.
    size_t left_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i <= orig_n);
        size_t res = i;
        value_type now = monoid.identity();
        left_bound(i, pred, 1, 0, ext_n, now, res);
        return res;
    }

    // maximum r where range [idx, r) meets the condition.
    size_t right_bound(size_t i, const std::function<bool(const value_type &)> &pred)
    {
        assert(i < orig_n);
        size_t res = i;
        value_type now = monoid.identity();
        right_bound(i, pred, 1, 0, ext_n, now, res);
        return res < orig_n ? res : orig_n;
    }
}; //class lazy_segment_tree
#endif

template <class T>
struct max_monoid
{
    using value_type = T;
    T identity()
    {
        return std::numeric_limits<T>::min();
        return 0;
    }
    T operator()(const T &x, const T &y)
    {
        return std::max(x,y);
    }
};

template <class T>
struct add_actor
{
    using value_type = T;
    value_type identity()
    {
        return 0;
    }
    void operator()(value_type &x, value_type y)
    {
        x += y;
    }
    template <class other>
    void act(other &x, value_type y)
    {
        x += y;
    }
};

struct solver
{
    solver()
    {
        int n,m; cin>>n>>m;
        lazy_segment_tree<max_monoid<i64>,add_actor<i64>> seg(n+1);
        const i64 inf=-max_monoid<i64>().identity();
        {
            vector<i64> init(1,0);
            seg.build(all(init));
        }
        vector<vector<pii>> iv(n+1);
        for(int i=0; i<m; ++i)
        {
            int l,r,a; cin>>l>>r>>a;
            iv[r].emplace_back(l,a);
        }
        for(int i=1; i<=n; ++i)
        {
            seg.update(i,inf+seg.fold(0,i));
            for(auto&& pr : iv[i])
            {
                int j,a; tie(j,a)=pr;
                seg.update(j,i+1,a);
            }
        }
        cout << seg.fold(0,n+1) << "\n";
    }
}; // struct solver


int main(int argc, char *argv[])
{
    u32 t; // loop count
#ifdef LOCAL
    t = 1;
#else
    t = 1; // single test case
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--)
    {
        solver();
    }
}
