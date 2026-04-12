/**
 * 
 */

// header {{{
#include <bits/stdc++.h>
using namespace std;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

using i8   = int8_t;
using u8   = uint8_t;
using i16  = int16_t;
using u16  = uint16_t;
using i32  = int32_t;
using u32  = uint32_t;
using i64  = int64_t;
using u64  = uint64_t;
#ifdef __SIZEOF_INT128__
using i128 = __int128;
using u128 = unsigned __int128;
#endif

using f32  = float;
using f64  = double;
using f80  = __float80;
using f128 = __float128;
// }}}

template<typename T> constexpr T PROCON_INF();
template<> constexpr i64 PROCON_INF<i64>() { return 1'010'000'000'000'000'017LL; }
template<> constexpr f64 PROCON_INF<f64>() { return 1e100; }

constexpr i64 INF  = PROCON_INF<i64>();
constexpr f64 FINF = PROCON_INF<f64>();

constexpr i64 MOD = 1'000'000'007LL;

constexpr f64 EPS = 1e-12;

constexpr f64 PI = 3.14159265358979323846;

// util {{{
#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define SLICE(f,c,l,r,...) (([&](decltype((c)) cccc, decltype((l)) llll, decltype((r)) rrrr) {\
    auto iiii = llll <= rrrr ? std::begin(cccc)+llll : std::end(cccc);\
    auto jjjj = llll <= rrrr ? std::begin(cccc)+rrrr : std::end(cccc);\
    return (f)(iiii, jjjj, ## __VA_ARGS__);\
})(c,l,r))

#define GENERIC(f) ([](auto&&... args) -> decltype(auto) { return (f)(std::forward<decltype(args)>(args)...); })

// BoolArray {{{
class BoolArray {
public:
    using value_type      = bool;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using iterator        = value_type*;
    using const_iterator  = const value_type*;
    using difference_type = ptrdiff_t;
    using size_type       = size_t;

    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    BoolArray() : BoolArray(0) {}
    explicit BoolArray(size_t n) : BoolArray(n,false) {}
    BoolArray(size_t n, bool value) : size_(n), data_(new bool[n]) {
        ALL(fill, *this, value);
    }

    BoolArray(initializer_list<bool> init) : size_(init.size()), data_(new bool[size_]) {
        ALL(copy, init, begin());
    }

    template<typename InputIt>
    BoolArray(InputIt first, InputIt last) {
        deque<bool> tmp(first, last);
        size_ = tmp.size();
        data_ = new bool[size_];
        ALL(copy, tmp, begin());
    }

    BoolArray(const BoolArray& other) : size_(other.size_), data_(new bool[size_]) {
        ALL(copy, other, begin());
    }

    BoolArray(BoolArray&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.data_ = nullptr;
    }

    BoolArray& operator=(const BoolArray& other) {
        if(this == &other) return *this;
        if(!data_ || size_ < other.size_) {
            delete[] data_;
            data_ = new bool[other.size_];
        }
        size_ = other.size_;
        ALL(copy, other, begin());
        return *this;
    }

    BoolArray& operator=(BoolArray&& other) noexcept {
        if(this == &other) return *this;
        size_ = other.size_;
        data_ = other.data_;
        other.data_ = nullptr;
        return *this;
    }

    BoolArray& operator=(initializer_list<bool> init) {
        if(!data_ || size_ < init.size()) {
            delete[] data_;
            data_ = new bool[init.size()];
        }
        size_ = init.size();
        ALL(copy, init, begin());
        return *this;
    }

    void swap(BoolArray& other) noexcept {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    ~BoolArray() {
        delete[] data_;
        data_ = nullptr;
    }

    bool      empty()    const noexcept { return size_ == 0; }
    size_type size()     const noexcept { return size_; }
    size_type max_size() const noexcept { return 1'010'000'000; }

    iterator       begin()        noexcept { return data_; }
    const_iterator begin()  const noexcept { return data_; }
    const_iterator cbegin() const noexcept { return data_; }

    iterator       end()        noexcept { return data_+size_; }
    const_iterator end()  const noexcept { return data_+size_; }
    const_iterator cend() const noexcept { return data_+size_; }

    reverse_iterator       rbegin()        noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin()  const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    reverse_iterator       rend()        noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend()  const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

    reference       operator[](size_type pos)       { return data_[pos]; }
    const_reference operator[](size_type pos) const { return data_[pos]; }

    bool*       data()       noexcept { return data_; }
    const bool* data() const noexcept { return data_; }

private:
    size_t size_;
    bool*  data_;
};

void swap(BoolArray& lhs, BoolArray& rhs) noexcept { lhs.swap(rhs); }

bool operator==(const BoolArray& lhs, const BoolArray& rhs) {
    return equal(begin(lhs), end(lhs), begin(rhs), end(rhs));
}
bool operator!=(const BoolArray& lhs, const BoolArray& rhs) { return !(lhs == rhs); }

bool operator<(const BoolArray& lhs, const BoolArray& rhs) {
    return lexicographical_compare(begin(lhs), end(lhs), begin(rhs), end(rhs));
}
bool operator> (const BoolArray& lhs, const BoolArray& rhs) { return rhs < lhs; }
bool operator<=(const BoolArray& lhs, const BoolArray& rhs) { return !(rhs < lhs); }
bool operator>=(const BoolArray& lhs, const BoolArray& rhs) { return !(lhs < rhs); }
// }}}

// 多次元 vector {{{
// 最内周が vector<bool> になるのを避けるための措置
template<typename T>
struct Array1Container {
    using type = vector<T>;
};
template<>
struct Array1Container<bool> {
    using type = BoolArray;
};

// イテレート用
template<typename T>
struct is_arrayn_container {
    static constexpr bool value = false;
};
template<typename T>
struct is_arrayn_container<vector<T>> {
    static constexpr bool value = true;
};
template<>
struct is_arrayn_container<BoolArray> {
    static constexpr bool value = true;
};

template<typename T>
auto arrayn_make(i64 n, T x) {
    using Cont = typename Array1Container<T>::type;
    return Cont(n, x);
}

template<typename T, typename... Args,
         enable_if_t<2 <= sizeof...(Args), nullptr_t> = nullptr>
auto arrayn_make(i64 n, Args... args) {
    auto inner = arrayn_make<T>(args...);
    return vector<decltype(inner)>(n, inner);
}

template<typename T, typename F>
enable_if_t<!is_arrayn_container<T>::value> arrayn_foreach(T& e, F f) {
    f(e);
}

template<typename T, typename F>
enable_if_t<is_arrayn_container<T>::value> arrayn_foreach(T& ary, F f) {
    for(auto& e : ary)
        arrayn_foreach(e, f);
}

template<typename T, typename U>
enable_if_t<is_arrayn_container<T>::value> arrayn_fill(T& ary, const U& x) {
    arrayn_foreach(ary, [&x](auto& e) { e = x; });
}
// }}}

// 多次元生配列 {{{
template<typename T, typename F>
enable_if_t<rank<T>::value==0> CARRAY_FOREACH(T& e, F f) {
    f(e);
}

template<typename Array, typename F>
enable_if_t<rank<Array>::value!=0> CARRAY_FOREACH(Array& ary, F f) {
    for(auto& e : ary)
        CARRAY_FOREACH(e, f);
}

template<typename Array, typename U>
enable_if_t<rank<Array>::value!=0> CARRAY_FILL(Array& ary, const U& v) {
    CARRAY_FOREACH(ary, [&v](auto& e) { e = v; });
}
// }}}

// メモ化ラッパー (8引数まで) {{{
template<i64 N1, typename F>
class Memoized1 {
    static_assert(N1 >= 1, "");
public:
    explicit Memoized1(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1) const {
        using R = decltype(f_(*this,x1));
        static bool done[N1] {};
        static R    memo[N1];
        if(!done[x1]) {
            memo[x1] = f_(*this,x1);
            done[x1] = true;
        }
        return memo[x1];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, typename F>
class Memoized2 {
    static_assert(N1 >= 1 && N2 >= 1, "");
public:
    explicit Memoized2(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2) const {
        using R = decltype(f_(*this,x1,x2));
        static bool done[N1][N2] {};
        static R    memo[N1][N2];
        if(!done[x1][x2]) {
            memo[x1][x2] = f_(*this,x1,x2);
            done[x1][x2] = true;
        }
        return memo[x1][x2];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, typename F>
class Memoized3 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1, "");
public:
    explicit Memoized3(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3) const {
        using R = decltype(f_(*this,x1,x2,x3));
        static bool done[N1][N2][N3] {};
        static R    memo[N1][N2][N3];
        if(!done[x1][x2][x3]) {
            memo[x1][x2][x3] = f_(*this,x1,x2,x3);
            done[x1][x2][x3] = true;
        }
        return memo[x1][x2][x3];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, typename F>
class Memoized4 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1, "");
public:
    explicit Memoized4(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4) const {
        using R = decltype(f_(*this,x1,x2,x3,x4));
        static bool done[N1][N2][N3][N4] {};
        static R    memo[N1][N2][N3][N4];
        if(!done[x1][x2][x3][x4]) {
            memo[x1][x2][x3][x4] = f_(*this,x1,x2,x3,x4);
            done[x1][x2][x3][x4] = true;
        }
        return memo[x1][x2][x3][x4];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, typename F>
class Memoized5 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1, "");
public:
    explicit Memoized5(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5));
        static bool done[N1][N2][N3][N4][N5] {};
        static R    memo[N1][N2][N3][N4][N5];
        if(!done[x1][x2][x3][x4][x5]) {
            memo[x1][x2][x3][x4][x5] = f_(*this,x1,x2,x3,x4,x5);
            done[x1][x2][x3][x4][x5] = true;
        }
        return memo[x1][x2][x3][x4][x5];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, typename F>
class Memoized6 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1, "");
public:
    explicit Memoized6(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6));
        static bool done[N1][N2][N3][N4][N5][N6] {};
        static R    memo[N1][N2][N3][N4][N5][N6];
        if(!done[x1][x2][x3][x4][x5][x6]) {
            memo[x1][x2][x3][x4][x5][x6] = f_(*this,x1,x2,x3,x4,x5,x6);
            done[x1][x2][x3][x4][x5][x6] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, typename F>
class Memoized7 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1, "");
public:
    explicit Memoized7(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6, i64 x7) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6,x7));
        static bool done[N1][N2][N3][N4][N5][N6][N7] {};
        static R    memo[N1][N2][N3][N4][N5][N6][N7];
        if(!done[x1][x2][x3][x4][x5][x6][x7]) {
            memo[x1][x2][x3][x4][x5][x6][x7] = f_(*this,x1,x2,x3,x4,x5,x6,x7);
            done[x1][x2][x3][x4][x5][x6][x7] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6][x7];
    }
private:
    const F f_;
};

template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, i64 N8, typename F>
class Memoized8 {
    static_assert(N1 >= 1 && N2 >= 1 && N3 >= 1 && N4 >= 1 && N5 >= 1 && N6 >= 1 && N7 >= 1 && N8 >= 1, "");
public:
    explicit Memoized8(F&& f) : f_(forward<F>(f)) {}
    decltype(auto) operator()(i64 x1, i64 x2, i64 x3, i64 x4, i64 x5, i64 x6, i64 x7, i64 x8) const {
        using R = decltype(f_(*this,x1,x2,x3,x4,x5,x6,x7,x8));
        static bool done[N1][N2][N3][N4][N5][N6][N7][N8] {};
        static R    memo[N1][N2][N3][N4][N5][N6][N7][N8];
        if(!done[x1][x2][x3][x4][x5][x6][x7][x8]) {
            memo[x1][x2][x3][x4][x5][x6][x7][x8] = f_(*this,x1,x2,x3,x4,x5,x6,x7,x8);
            done[x1][x2][x3][x4][x5][x6][x7][x8] = true;
        }
        return memo[x1][x2][x3][x4][x5][x6][x7][x8];
    }
private:
    const F f_;
};

template<i64 N1, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized1<N1,F>(forward<F>(f));
}
template<i64 N1, i64 N2, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized2<N1,N2,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized3<N1,N2,N3,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized4<N1,N2,N3,N4,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized5<N1,N2,N3,N4,N5,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized6<N1,N2,N3,N4,N5,N6,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized7<N1,N2,N3,N4,N5,N6,N7,F>(forward<F>(f));
}
template<i64 N1, i64 N2, i64 N3, i64 N4, i64 N5, i64 N6, i64 N7, i64 N8, typename F>
decltype(auto) MEMOIZE(F&& f) {
    return Memoized8<N1,N2,N3,N4,N5,N6,N7,N8,F>(forward<F>(f));
}

// }}}

// lambda で再帰 {{{
template<typename F>
class FixPoint {
public:
    explicit constexpr FixPoint(F&& f) : f_(forward<F>(f)) {}

    template<typename... Args>
    constexpr decltype(auto) operator()(Args&&... args) const {
        return f_(*this, forward<Args>(args)...);
    }

private:
    const F f_;
};

template<typename F>
decltype(auto) FIX(F&& f) {
    return FixPoint<F>(forward<F>(f));
}
// }}}

// tuple {{{
template<typename... TS,
         enable_if_t<0 < sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_head(const tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, size_t i, size_t... is>
constexpr auto tuple_tail_helper(const tuple<TS...>& t, index_sequence<i,is...>) {
    return make_tuple(get<is>(t)...);
}

template<typename... TS,
         enable_if_t<1 == sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_tail(const tuple<TS...>&) {
    return make_tuple();
}

template<typename... TS,
         enable_if_t<1 < sizeof...(TS), nullptr_t> = nullptr>
constexpr auto tuple_tail(const tuple<TS...>& t) {
    return tuple_tail_helper(t, make_index_sequence<sizeof...(TS)>());
}
// }}}

// FST/SND {{{
template<typename T1, typename T2>
T1& FST(pair<T1,T2>& p) {
    return p.first;
}

template<typename T1, typename T2>
const T1& FST(const pair<T1,T2>& p) {
    return p.first;
}

template<typename T1, typename T2>
T2& SND(pair<T1,T2>& p) {
    return p.second;
}

template<typename T1, typename T2>
const T2& SND(const pair<T1,T2>& p) {
    return p.second;
}

template<typename... TS, enable_if_t<1 <= sizeof...(TS), nullptr_t> = nullptr>
auto& FST(tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, enable_if_t<1 <= sizeof...(TS), nullptr_t> = nullptr>
const auto& FST(const tuple<TS...>& t) {
    return get<0>(t);
}

template<typename... TS, enable_if_t<2 <= sizeof...(TS), nullptr_t> = nullptr>
auto& SND(tuple<TS...>& t) {
    return get<1>(t);
}

template<typename... TS, enable_if_t<2 <= sizeof...(TS), nullptr_t> = nullptr>
const auto& SND(const tuple<TS...>& t) {
    return get<1>(t);
}
// }}}

template<typename T1, typename T2, typename Comp=less<>,
         enable_if_t<is_signed<T1>::value != is_unsigned<T2>::value, nullptr_t> = nullptr>
common_type_t<T1,T2> MAX(T1 x, T2 y, Comp comp={}) {
    return max<common_type_t<T1,T2>>(x, y, comp);
}

template<typename T, typename Comp=less<>>
const T& MAX(const T& x, const T& y, Comp comp={}) {
    return max(x, y, comp);
}

template<typename T, typename Comp=less<>>
T MAX(initializer_list<T> ilist, Comp comp={}) {
    return max(ilist, comp);
}

template<typename T1, typename T2, typename Comp=less<>,
         enable_if_t<is_signed<T1>::value != is_unsigned<T2>::value, nullptr_t> = nullptr>
common_type_t<T1,T2> MIN(T1 x, T2 y, Comp comp={}) {
    return min<common_type_t<T1,T2>>(x, y, comp);
}

template<typename T, typename Comp=less<>>
const T& MIN(const T& x, const T& y, Comp comp={}) {
    return min(x, y, comp);
}

template<typename T, typename Comp=less<>>
T MIN(initializer_list<T> ilist, Comp comp={}) {
    return min(ilist, comp);
}

template<typename C>
i64 SIZE(const C& c) { return static_cast<i64>(c.size()); }

template<typename T, size_t N>
i64 SIZE(const T (&)[N]) { return static_cast<i64>(N); }

bool is_odd (i64 x) { return x % 2 != 0; }
bool is_even(i64 x) { return x % 2 == 0; }

template<typename T> i64 cmp(T x, T y) { return (y<x) - (x<y); }
template<typename T> i64 sgn(T x) { return cmp(x, T(0)); }

// lo:OK, hi:NG
template<typename Pred>
i64 bisect_integer(i64 lo, i64 hi, Pred pred) {
    assert(lo < hi);

    while(lo+1 < hi) {
        i64 mid = (lo+hi) / 2;
        if(pred(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

template<typename Pred>
f64 bisect_real(f64 lo, f64 hi, Pred pred, i64 iter=100) {
    assert(lo < hi);

    REP(_, iter) {
        f64 mid = (lo+hi) / 2;
        if(pred(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

i64 ipow(i64 x, i64 e) {
    assert(e >= 0);
    i64 res = 1;
    REP(_, e) {
        res *= x;
    }
    return res;
}

i64 isqrt(i64 x) {
    assert(x >= 0);

    i64 lo = 0;
    i64 hi = MIN(x/2+2, 3037000500LL);
    return bisect_integer(lo, hi, [x](i64 r) { return r*r <= x; });
}

// 0 <= ilog2(x) <= 62
i64 ilog2(i64 x) {
    assert(x > 0);
    return 63 - __builtin_clzll(x);
}

// 0 <= ilog10(x) <= 18
i64 ilog10(i64 x) {
    assert(x > 0);
    static constexpr i64 TABLE[18] {
        9LL,
        99LL,
        999LL,
        9999LL,
        99999LL,
        999999LL,
        9999999LL,
        99999999LL,
        999999999LL,
        9999999999LL,
        99999999999LL,
        999999999999LL,
        9999999999999LL,
        99999999999999LL,
        999999999999999LL,
        9999999999999999LL,
        99999999999999999LL,
        999999999999999999LL,
    };
    REP(i, SIZE(TABLE)) {
        if(x <= TABLE[i]) return i;
    }
    return SIZE(TABLE);
}

// Haskell の divMod と同じ
pair<i64,i64> divmod(i64 a, i64 b) {
    i64 q = a / b;
    i64 r = a % b;
    if((b>0 && r<0) || (b<0 && r>0)) {
        --q;
        r += b;
    }
    return {q,r};
}

i64 div_ceil(i64 a, i64 b) {
    i64 q = a / b;
    i64 r = a % b;
    if((b>0 && r>0) || (b<0 && r<0))
        ++q;
    return q;
}

i64 div_floor(i64 a, i64 b) {
    return divmod(a,b).first;
}

i64 modulo(i64 a, i64 b) {
    return divmod(a,b).second;
}

bool feq(f64 x, f64 y, f64 eps=EPS) {
    return fabs(x-y) < eps;
}

template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

template<typename Pred>
i64 arg_find(i64 lo, i64 hi, Pred pred) {
    assert(lo < hi);

    FOR(x, lo, hi) {
        if(pred(x)) return x;
    }
    return INF;
}

template<typename F>
i64 arg_max(i64 lo, i64 hi, F f) {
    assert(lo < hi);

    i64 res = lo;
    auto ymax = f(lo);
    FOR(x, lo+1, hi) {
        if(chmax(ymax, f(x)))
            res = x;
    }
    return res;
}

template<typename F>
i64 arg_min(i64 lo, i64 hi, F f) {
    assert(lo < hi);

    i64 res = lo;
    auto ymin = f(lo);
    FOR(x, lo+1, hi) {
        if(chmin(ymin, f(x)))
            res = x;
    }
    return res;
}

template<typename Pred>
i64 arg_find_r(i64 lo, i64 hi, Pred pred) {
    i64 x = arg_find(-hi+1, lo+1, [pred](i64 xx) { return pred(-xx); });
    return x == INF ? INF : -x;
}

template<typename F>
i64 arg_max_r(i64 lo, i64 hi, F f) {
    return -arg_max(-hi+1, lo+1, [f](i64 x) { return f(-x); });
}

template<typename F>
i64 arg_min_r(i64 lo, i64 hi, F f) {
    return -arg_min(-hi+1, lo+1, [f](i64 x) { return f(-x); });
}

template<typename ForwardIt, typename T, typename Comp=less<>>
ForwardIt bsearch_find(ForwardIt first, ForwardIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == last || comp(x,*it)) return last;
    return it;
}

// x 未満の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt bsearch_lt(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = lower_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x 以下の最後の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt bsearch_le(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    auto it = upper_bound(first, last, x, comp);
    if(it == first) return last;
    return prev(it);
}

// x より大きい最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt bsearch_gt(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    return upper_bound(first, last, x, comp);
}

// x 以上の最初の要素
template<typename BidiIt, typename T, typename Comp=less<>>
BidiIt bsearch_ge(BidiIt first, BidiIt last, const T& x, Comp comp={}) {
    return lower_bound(first, last, x, comp);
}

template<typename InputIt>
auto SUM(InputIt first, InputIt last) {
    using T = typename iterator_traits<InputIt>::value_type;
    return accumulate(first, last, T());
}

template<typename ForwardIt, typename UnaryOperation>
ForwardIt transform_self(ForwardIt first, ForwardIt last, UnaryOperation op) {
    return transform(first, last, first, op);
}

template<typename C>
void UNIQ(C& c) {
    c.erase(ALL(unique,c), end(c));
}

template<typename BinaryFunc>
auto FLIP(BinaryFunc f) {
    return [f](const auto& x, const auto& y) {
        return f(y,x);
    };
}

template<typename BinaryFunc, typename UnaryFunc>
auto ON(BinaryFunc bf, UnaryFunc uf) {
    return [bf,uf](const auto& x, const auto& y) {
        return bf(uf(x), uf(y));
    };
}

template<typename F>
auto LT_ON(F f) { return ON(less<>(), f); }

template<typename F>
auto GT_ON(F f) { return ON(greater<>(), f); }

template<typename F>
auto EQ_ON(F f) { return ON(equal_to<>(), f); }

template<typename F>
auto NE_ON(F f) { return ON(not_equal_to<>(), f); }

template<typename Comp=less<>>
auto EQUIV(Comp comp={}) {
    return [comp](const auto& lhs, const auto& rhs) {
        return !comp(lhs,rhs) && !comp(rhs,lhs);
    };
}

struct IDENTITY {
    template<typename T>
    constexpr T&& operator()(T&& x) const noexcept {
        return forward<T>(x);
    }
};

template<typename ForwardIt>
ForwardIt next_bounded(ForwardIt last, ForwardIt it, i64 n=1) {
    auto bound = distance(it, last);
    return next(it, MIN(n, bound));
}

template<typename ForwardIt>
ForwardIt prev_bounded(ForwardIt first, ForwardIt it, i64 n=1) {
    auto bound = distance(first, it);
    return prev(it, MIN(n, bound));
}

template<typename ForwardIt>
void advance_bounded(ForwardIt first, ForwardIt last, ForwardIt& it, i64 n) {
    if(n > 0) {
        auto bound = distance(it, last);
        advance(it, MIN(n, bound));
    }
    else if(n < 0) {
        auto bound = distance(it, first);
        advance(it, MAX(n, bound));
    }
}

char digit_chr(i64 n) {
    return static_cast<char>('0' + n);
}

i64 digit_ord(char c) {
    return c - '0';
}

char lower_chr(i64 n) {
    return static_cast<char>('a' + n);
}

i64 lower_ord(char c) {
    return c - 'a';
}

char upper_chr(i64 n) {
    return static_cast<char>('A' + n);
}

i64 upper_ord(char c) {
    return c - 'A';
}

// 出力は operator<< を直接使わず、このテンプレート経由で行う
// 提出用出力とデバッグ用出力を分けるため
template<typename T, typename Enable=void>
struct Formatter {
    static ostream& write_str(ostream& out, const T& x)  { return out << x; }
    static ostream& write_repr(ostream& out, const T& x) { return out << x; }
};

template<typename T>
ostream& WRITE_STR(ostream& out, const T& x) {
    return Formatter<T>::write_str(out, x);
}

template<typename T>
ostream& WRITE_REPR(ostream& out, const T& x) {
    return Formatter<T>::write_repr(out, x);
}

template<typename InputIt>
ostream& WRITE_JOIN_STR(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        WRITE_STR(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& WRITE_JOIN_REPR(ostream& out, InputIt first, InputIt last, const string& sep) {
    while(first != last) {
        WRITE_REPR(out, *first++);
        if(first != last)
            out << sep;
    }
    return out;
}

template<typename InputIt>
ostream& WRITE_RANGE_STR(ostream& out, InputIt first, InputIt last) {
    return WRITE_JOIN_STR(out, first, last, " ");
}

template<typename InputIt>
ostream& WRITE_RANGE_REPR(ostream& out, InputIt first, InputIt last) {
    out << "[";
    WRITE_JOIN_REPR(out, first, last, ", ");
    out << "]";
    return out;
}

template<typename T>
void FROM_STR(const string& s, T& x) {
    istringstream in(s);
    in >> x;
}

template<typename T>
string TO_STR(const T& x) {
    ostringstream out;
    WRITE_STR(out, x);
    return out.str();
}

template<typename T>
string TO_REPR(const T& x) {
    ostringstream out;
    WRITE_REPR(out, x);
    return out.str();
}

template<typename InputIt>
string RANGE_TO_STR(InputIt first, InputIt last) {
    ostringstream out;
    WRITE_RANGE_STR(out, first, last);
    return out.str();
}

template<typename InputIt>
string RANGE_TO_REPR(InputIt first, InputIt last) {
    ostringstream out;
    WRITE_RANGE_REPR(out, first, last);
    return out.str();
}

template<typename InputIt>
string JOIN(InputIt first, InputIt last, const string& sep) {
    ostringstream out;
    WRITE_JOIN_STR(out, first, last, sep);
    return out.str();
}

template<>
struct Formatter<i64> {
    static ostream& write_str(ostream& out, i64 x) {
        return out << x;
    }
    static ostream& write_repr(ostream& out, i64 x) {
        if(x == INF) return out << "INF";
        if(x == -INF) return out << "-INF";
        return out << x;
    }
};

template<>
struct Formatter<f64> {
    static ostream& write_str(ostream& out, f64 x) {
        return out << x;
    }
    static ostream& write_repr(ostream& out, f64 x) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
        if(x == FINF) return out << "FINF";
        if(x == -FINF) return out << "-FINF";
#pragma GCC diagnostic pop
        return out << x;
    }
};

template<typename T>
struct Formatter<vector<T>> {
    static ostream& write_str(ostream& out, const vector<T>& v) {
        return WRITE_RANGE_STR(out, begin(v), end(v));
    }
    static ostream& write_repr(ostream& out, const vector<T>& v) {
        out << "vector";
        return WRITE_RANGE_REPR(out, begin(v), end(v));
    }
};

template<>
struct Formatter<BoolArray> {
    static ostream& write_str(ostream& out, const BoolArray& a) {
        return WRITE_RANGE_STR(out, begin(a), end(a));
    }
    static ostream& write_repr(ostream& out, const BoolArray& a) {
        out << "BoolArray";
        return WRITE_RANGE_REPR(out, begin(a), end(a));
    }
};

template<typename T1, typename T2>
struct Formatter<pair<T1,T2>> {
    static ostream& write_str(ostream& out, const pair<T1,T2>& p) {
        WRITE_STR(out, p.first);
        out << ' ';
        WRITE_STR(out, p.second);
        return out;
    }
    static ostream& write_repr(ostream& out, const pair<T1,T2>& p) {
        out << "(";
        WRITE_REPR(out, p.first);
        out << ",";
        WRITE_REPR(out, p.second);
        out << ")";
        return out;
    }
};

template<typename... TS>
struct Formatter<tuple<TS...>> {
    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& write_str_impl(ostream& out, const tuple<TS...>&) {
        return out;
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& write_str_impl(ostream& out, const tuple<TS...>& t) {
        if(I != 0) out << ' ';
        WRITE_STR(out, get<I>(t));
        return write_str_impl<I+1>(out, t);
    }

    template<size_t I=0, enable_if_t<I == sizeof...(TS), nullptr_t> = nullptr>
    static ostream& write_repr_impl(ostream& out, const tuple<TS...>&) {
        if(sizeof...(TS) == 0) out << "(";
        return out << ")";
    }
    template<size_t I=0, enable_if_t<I < sizeof...(TS), nullptr_t> = nullptr>
    static ostream& write_repr_impl(ostream& out, const tuple<TS...>& t) {
        if(I == 0)
            out << "(";
        else
            out << ",";
        WRITE_REPR(out, get<I>(t));
        return write_repr_impl<I+1>(out, t);
    }

    static ostream& write_str(ostream& out, const tuple<TS...>& t) {
        return write_str_impl(out, t);
    }
    static ostream& write_repr(ostream& out, const tuple<TS...>& t) {
        return write_repr_impl(out, t);
    }
};

template<typename T>
void RD(T& x) {
    cin >> x;
#ifdef PROCON_LOCAL
    assert(cin);
#endif
}

template<typename T>
void RD1(T& x) {
    RD(x);
    --x;
}

template<typename T>
auto RD_ARRAY(i64 n) {
    auto res = arrayn_make<T>(n, T());
    arrayn_foreach(res, [](T& e) { RD(e); });
    return res;
}

template<typename T>
auto RD1_ARRAY(i64 n) {
    auto res = arrayn_make<T>(n, T());
    arrayn_foreach(res, [](T& e) { RD1(e); });
    return res;
}

template<typename T>
auto RD_ARRAY2(i64 h, i64 w) {
    auto res = arrayn_make<T>(h,w, T());
    arrayn_foreach(res, [](T& e) { RD(e); });
    return res;
}

template<typename T>
auto RD1_ARRAY2(i64 h, i64 w) {
    auto res = arrayn_make<T>(h,w, T());
    arrayn_foreach(res, [](T& e) { RD1(e); });
    return res;
}

template<typename T1, typename T2>
pair<T1,T2> RD_PAIR() {
    T1 x; RD(x);
    T2 y; RD(y);
    return { x, y };
}

template<typename T1, typename T2>
pair<T1,T2> RD1_PAIR() {
    T1 x; RD1(x);
    T2 y; RD1(y);
    return { x, y };
}

template<typename... TS,
         enable_if_t<0 == sizeof...(TS), nullptr_t> = nullptr>
auto RD_TUPLE() {
    return make_tuple();
}

template<typename T, typename... TS>
auto RD_TUPLE() {
    T x; RD(x);
    return tuple_cat(make_tuple(x), RD_TUPLE<TS...>());
}

template<typename... TS,
         enable_if_t<0 == sizeof...(TS), nullptr_t> = nullptr>
auto RD1_TUPLE() {
    return make_tuple();
}

template<typename T, typename... TS>
auto RD1_TUPLE() {
    T x; RD1(x);
    return tuple_cat(make_tuple(x), RD_TUPLE<TS...>());
}

void PRINT() {}

template<typename T, typename... TS>
void PRINT(const T& x, const TS& ...args) {
    WRITE_STR(cout, x);
    if(sizeof...(args)) {
        cout << ' ';
        PRINT(args...);
    }
}

template<typename... TS>
void PRINTLN(const TS& ...args) {
    PRINT(args...);
    cout << '\n';
}

[[noreturn]] void EXIT() {
    cout.flush();
#ifdef PROCON_LOCAL
    cerr.flush();
    exit(0);
#else
    _Exit(0);
#endif
}

template<typename... TS, enable_if_t<1 == sizeof...(TS), nullptr_t> = nullptr>
void DBG_IMPL(i64 line, const char* expr, const tuple<TS...>& value) {
#ifdef PROCON_LOCAL
    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    WRITE_REPR(cerr, get<0>(value));
    cerr << "\n";
#endif
}

template<typename... TS, enable_if_t<2 <= sizeof...(TS), nullptr_t> = nullptr>
void DBG_IMPL(i64 line, const char* expr, const tuple<TS...>& value) {
#ifdef PROCON_LOCAL
    cerr << "[L " << line << "]: ";
    cerr << "(" << expr << ") = ";
    WRITE_REPR(cerr, value);
    cerr << "\n";
#endif
}

template<typename T, size_t N>
void DBG_CARRAY_IMPL(i64 line, const char* expr, const T (&ary)[N]) {
#ifdef PROCON_LOCAL
    cerr << "[L " << line << "]: ";
    cerr << expr << " = ";
    WRITE_RANGE_REPR(cerr, begin(ary), end(ary));
    cerr << "\n";
#endif
}

template<typename InputIt>
void DBG_RANGE_IMPL(i64 line, const char* expr1, const char* expr2, InputIt first, InputIt last) {
#ifdef PROCON_LOCAL
    cerr << "[L " << line << "]: ";
    cerr << expr1 << "," << expr2 << " = ";
    WRITE_RANGE_REPR(cerr, first, last);
    cerr << "\n";
#endif
}

#define DBG(args...) DBG_IMPL(__LINE__, CPP_STR_I(args), make_tuple(args))
#define DBG_CARRAY(expr) DBG_CARRAY_IMPL(__LINE__, CPP_STR(expr), (expr))
#define DBG_RANGE(first,last) DBG_RANGE_IMPL(__LINE__, CPP_STR(first), CPP_STR(last), (first), (last))

#define PAIR  make_pair
#define TUPLE make_tuple
// }}}

// init {{{
struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
#ifdef PROCON_LOCAL
        cerr << fixed << setprecision(IOS_PREC);
#endif
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;
// }}}

// num {{{

// 事前条件: a >= 0, b >= 0
i64 gcd_impl(i64 a, i64 b) {
    if(b == 0) return a;
    return gcd_impl(b, a%b);
}

// gcd(0,0) = 0
i64 gcd(i64 a, i64 b) {
    return gcd_impl(abs(a), abs(b));
}

// lcm(0,x) は未定義
i64 lcm(i64 a, i64 b) {
    assert(a != 0 && b != 0);
    a = abs(a);
    b = abs(b);
    return a / gcd_impl(a,b) * b;
}

// 事前条件: a >= 0, b >= 0
i64 extgcd_impl(i64 a, i64 b, i64& x, i64& y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    i64 g = extgcd_impl(b, a%b, y, x);
    y -= a/b * x;
    return g;
}

// g=gcd(a,b), および ax+by=g の整数解 (x0,y0) を求める
// (g,x0,y0) を返す
// g!=0 のとき、一般解は (x,y) = (x0+m*b/g, y0-m*a/g) で与えられる(mは整数)
tuple<i64,i64,i64> extgcd(i64 a, i64 b) {
    i64 x, y;
    i64 g = extgcd_impl(abs(a), abs(b), x, y);
    x *= sgn(a);
    y *= sgn(b);
    return make_tuple(g, x, y);
}

vector<i64> divisors_proper(i64 n) {
    if(n == 1) return {};
    vector<i64> res(1, 1);

    i64 d = 2;
    for(; d*d < n; ++d) {
        if(n % d == 0) {
            res.emplace_back(d);
            res.emplace_back(n/d);
        }
    }
    if(d*d == n)
        res.emplace_back(d);

    return res;
}

vector<i64> divisors(i64 n) {
    vector<i64> res = divisors_proper(n);
    res.emplace_back(n);
    return res;
}

// 素因数分解
// (素因数,指数) のリストを返す
// n >= 1 でなければならない
// n == 1 の場合、空リストを返す
vector<pair<i64,i64>> factorize(i64 n) {
    assert(n >= 1);

    vector<pair<i64,i64>> res;

    i64 m = n;
    for(i64 i = 2; i*i <= n; ++i) {
        if(m == 1) break;
        i64 e = 0;
        while(m % i == 0) {
            ++e;
            m /= i;
        }
        if(e) res.emplace_back(i, e);
    }
    if(m > 1) res.emplace_back(m, 1);

    return res;
}

bool is_square(i64 x) {
    i64 r = isqrt(x);
    return r*r == x;
}

// Miller-Rabin 法
//
// 参考: http://miller-rabin.appspot.com/
bool is_prime_u32(u32 n) {
    static constexpr u32 AS[] {
         2,
         7,
        61,
    };

    static const auto mulmod32 = [](u32 a, u32 b, u32 m) -> u32 {
        u64 res = a;
        res *= b;
        res %= m;
        return static_cast<u32>(res);
    };

    static const auto powmod32 = [](u32 a, u32 b, u32 m) -> u32 {
        u32 res = 1;
        while(b > 0) {
            if(b & 1)
                res = mulmod32(res, a, m);
            a = mulmod32(a, a, m);
            b >>= 1;
        }
        return res;
    };

    if(n <= 1)     return false;
    if(n == 2)     return true;
    if(n % 2 == 0) return false;

    u32 d = n-1;
    u32 s = __builtin_ctz(d);
    d >>= s;

    for(u32 a : AS) {
        if(a >= n) a %= n;
        if(a == 0) continue;

        u32 x = powmod32(a, d, n);
        if(x == 1 || x == n-1) continue;

        u32 r;
        for(r = 1; r < s; ++r) {
            x = mulmod32(x, x, n);
            if(x == 1)   return false;
            if(x == n-1) break;
        }
        if(r == s) return false;
    }

    return true;
}

bool is_prime_u64(u64 n) {
    static constexpr u64 AS[] {
                 2,
               325,
              9375,
             28178,
            450775,
           9780504,
        1795265022,
    };

    static const auto mulmod64 = [](u64 a, u64 b, u64 m) -> u64 {
        u128 res = a;
        res *= b;
        res %= m;
        return static_cast<u64>(res);
    };

    static const auto powmod64 = [](u64 a, u64 b, u64 m) -> u64 {
        u64 res = 1;
        while(b > 0) {
            if(b & 1)
                res = mulmod64(res, a, m);
            a = mulmod64(a, a, m);
            b >>= 1;
        }
        return res;
    };

    if(n <= numeric_limits<u32>::max()) return is_prime_u32(static_cast<u32>(n));
    if(n % 2 == 0) return false;

    u64 d = n-1;
    u64 s = __builtin_ctzll(d);
    d >>= s;

    for(u64 a : AS) {
        if(a >= n) a %= n;
        if(a == 0) continue;

        u64 x = powmod64(a, d, n);
        if(x == 1 || x == n-1) continue;

        u64 r;
        for(r = 1; r < s; ++r) {
            x = mulmod64(x, x, n);
            if(x == 1)   return false;
            if(x == n-1) break;
        }
        if(r == s) return false;
    }

    return true;
}

bool is_prime(i64 n) {
    assert(n >= 0);
    return is_prime_u64(static_cast<u64>(n));
}

// 二分累乗
template<typename Monoid>
Monoid pow_binary(Monoid x, i64 e) {
    assert(e >= 0);

    Monoid res(1);  // 行列などの場合はここを適当に変える
    Monoid cur = x;
    while(e > 0) {
        if(e & 1)
            res *= cur;
        cur *= cur;
        e >>= 1;
    }
    return res;
}

// mod m での a の逆元
// a ⊥ m でなければならない
i64 inv_mod(i64 a, i64 m) {
    i64 g,x0; tie(g,x0,ignore) = extgcd(a, m);
    assert(g == 1);
    return modulo(x0, m);
}

template<i64 P>
struct ModPT {
    static_assert(P >= 2, "P must be a prime");
    i64 v_;  // [0,P)

    ModPT() : v_(0) {}
    ModPT(i64 v) : v_(modulo(v,P)) {}

    ModPT operator-() const {
        return ModPT(-v_);
    }
    ModPT& operator+=(ModPT rhs) {
        v_ += rhs.v_;
        v_ %= P;
        return *this;
    }
    ModPT& operator-=(ModPT rhs) {
        v_ += P;
        v_ -= rhs.v_;
        v_ %= P;
        return *this;
    }
    ModPT& operator*=(ModPT rhs) {
        v_ *= rhs.v_;
        v_ %= P;
        return *this;
    }

    ModPT& operator++() {
        return *this += 1;
    }
    ModPT& operator--() {
        return *this -= 1;
    }
    ModPT operator++(int) {
        ModPT res(*this);
        ++*this;
        return res;
    }
    ModPT operator--(int) {
        ModPT res(*this);
        --*this;
        return res;
    }

    explicit operator i64() const { return v_; }

    ModPT inv() const {
        return ModPT(inv_mod(v_,P));
    }
};

template<i64 P>
ModPT<P> operator+(ModPT<P> lhs, ModPT<P> rhs) { return ModPT<P>(lhs) += rhs; }
template<i64 P>
ModPT<P> operator+(ModPT<P> lhs, i64 rhs) { return ModPT<P>(lhs) += rhs; }
template<i64 P>
ModPT<P> operator+(i64 lhs, ModPT<P> rhs) { return ModPT<P>(rhs) += lhs; }
template<i64 P>
ModPT<P> operator-(ModPT<P> lhs, ModPT<P> rhs) { return ModPT<P>(lhs) -= rhs; }
template<i64 P>
ModPT<P> operator-(ModPT<P> lhs, i64 rhs) { return ModPT<P>(lhs) -= rhs; }
template<i64 P>
ModPT<P> operator-(i64 lhs, ModPT<P> rhs) { return ModPT<P>(rhs) -= lhs; }
template<i64 P>
ModPT<P> operator*(ModPT<P> lhs, ModPT<P> rhs) { return ModPT<P>(lhs) *= rhs; }
template<i64 P>
ModPT<P> operator*(ModPT<P> lhs, i64 rhs) { return ModPT<P>(lhs) *= rhs; }
template<i64 P>
ModPT<P> operator*(i64 lhs, ModPT<P> rhs) { return ModPT<P>(rhs) *= lhs; }

template<i64 P>
bool operator==(ModPT<P> lhs, ModPT<P> rhs) { return lhs.v_ == rhs.v_; }
template<i64 P>
bool operator==(ModPT<P> lhs, i64 rhs) { return lhs == ModPT<P>(rhs); }
template<i64 P>
bool operator==(i64 lhs, ModPT<P> rhs) { return ModPT<P>(lhs) == rhs; }
template<i64 P>
bool operator!=(ModPT<P> lhs, ModPT<P> rhs) { return !(lhs == rhs); }
template<i64 P>
bool operator!=(ModPT<P> lhs, i64 rhs) { return !(lhs == rhs); }
template<i64 P>
bool operator!=(i64 lhs, ModPT<P> rhs) { return !(lhs == rhs); }

template<i64 P>
istream& operator>>(istream& in, ModPT<P>& x) {
    return in >> x.v_;
}

template<i64 P>
struct Formatter<ModPT<P>> {
    static ostream& write_str(ostream& out, ModPT<P> x) {
        return WRITE_STR(out, x.v_);
    }
    static ostream& write_repr(ostream& out, ModPT<P> x) {
        return WRITE_REPR(out, x.v_);
    }
};

using ModP = ModPT<MOD>;

// エラトステネスのふるい
template<i64 N>
bool (&is_prime_table())[N] {
    static_assert(N >= 3, "");
    static bool prime[N] {};

    if(!prime[2]) {
        fill(begin(prime)+2, end(prime), true);
        for(i64 i = 2; i*i <= N-1; ++i) {
            if(!prime[i]) continue;
            for(i64 j = i+i; j < N; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

// F(0) = 0
// F(1) = 1
// F(n) = F(n-1) + F(n-2)
//
// // decltype(auto) で受けると SIZE() が使える (auto だとポインタになってしまう)
// decltype(auto) fib = fibonacci_table<1000>();
template<i64 N>
ModP (&fibonacci_table())[N] {
    static_assert(N >= 2, "");
    static ModP fib[N] {};

    if(fib[1] != 1) {
        fib[0] = 0;
        fib[1] = 1;
        FOR(i, 2, N) {
            fib[i] = fib[i-1] + fib[i-2];
        }
    }
    return fib;
}

template<i64 N>
ModP (&factorial_table())[N] {
    static_assert(N >= 1, "");
    static ModP fac[N] {};

    if(fac[0] != 1) {
        fac[0] = 1;
        FOR(i, 1, N) {
            fac[i] = i * fac[i-1];
        }
    }
    return fac;
}

template<i64 N>
ModP (&ifactorial_table())[N] {
    static_assert(N >= 1, "");
    static ModP ifac[N] {};

    if(ifac[0] != 1) {
        decltype(auto) fac = factorial_table<N>();
        ifac[N-1] = fac[N-1].inv();
        for(i64 i = N-2; i >= 0; --i) {
            ifac[i] = (i+1) * ifac[i+1];
        }
    }
    return ifac;
}

ModP permutation_count_fac(i64 n, i64 r, const ModP* fac, const ModP* ifac) {
    if(n < r) return 0;
    return fac[n] * ifac[n-r];
}

template<i64 H, i64 W>
ModP (&combination_count_table())[H][W] {
    static_assert(W >= 1 && H >= W, "");
    static ModP dp[H][W] {};

    if(dp[0][0] != 1) {
        REP(i, H) {
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        FOR(i, 1, H) FOR(j, 1, i) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp;
}

template<i64 H, i64 W>
auto combination_count_func() {
    static_assert(W >= 1 && H >= W, "");
    return MEMOIZE<H,W>([](auto&& self, i64 n, i64 r) -> ModP {
        if(n <  r) return 0;
        if(r == 0) return 1;
        if(n == r) return 1;
        return self(n-1,r-1) + self(n-1,r);
    });
}

ModP combination_count_fac(i64 n, i64 r, const ModP* fac, const ModP* ifac) {
    if(n < r) return 0;
    return fac[n] * ifac[r] * ifac[n-r];
}

// 分割数 P(n,k) (n を k 個の正整数の和で表す場合の数)
//
// 「n を 最大値 k の正整数の和で表す場合の数」でもある。
// 「n を k 個『以下』の正整数の和で表す場合の数」は sum(P(n,i)) (1<=i<=k)
// 「n を k 個の『非負整数』の和で表す場合の数」は P(n+k,k)
//
// P(0,0) = 1
// P(n,0) = 0
// P(0,k) = 0
// n < k のとき P(n,k) = 0
// P(n,1) = 1
// P(n,n) = 1
template<i64 H, i64 W>
ModP (&partition_count_table())[H][W] {
    static_assert(W >= 1 && H >= W, "");
    static ModP dp[H][W] {};

    if(dp[0][0] != 1) {
        REP(j, W) {
            dp[j][j] = 1;
        }
        FOR(i, 2, H) {
            dp[i][1] = 1;
        }
        FOR(i, 3, H) {
            FOR(j, 2, MIN(i,W)) {
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
        }
    }
    return dp;
}

// 分割数 メモ化再帰版
template<i64 H, i64 W>
auto partition_count_func() {
    static_assert(W >= 1 && H >= W, "");
    return MEMOIZE<H,W>([](auto&& self, i64 n, i64 k) -> ModP {
        if(n <  k) return 0;
        if(n == k) return 1;
        if(k == 1) return 1;
        return self(n-1,k-1) + self(n-k,k);
    });
}

// }}}

//--------------------------------------------------------------------

template<typename Enum>
struct Formatter<Enum, enable_if_t<is_enum<Enum>::value>> {
    static ostream& write_str(ostream& out, Enum x) {
        return WRITE_STR(out, static_cast<underlying_type_t<Enum>>(x));
    }
    static ostream& write_repr(ostream& out, Enum x) {
        return WRITE_REPR(out, static_cast<underlying_type_t<Enum>>(x));
    }
};

void solve() {
    enum class Move { L, R };

    i64 N; RD(N);
    auto A = RD_ARRAY<i64>(N);

    auto moves = arrayn_make<Move>(N,N, Move::L);
    auto dp = arrayn_make<i64>(N,N, 0);
    REP(i, N) {
        dp[i][i] = A[i];
    }
    FOR(d, 1, N) REP(l, N-d) {
        i64 r = l + d;
        i64 zl = A[l] - dp[l+1][r];
        i64 zr = A[r] - dp[l][r-1];
        moves[l][r] = zl < zr ? Move::R : Move::L;
        dp[l][r] = MAX(zl,zr);
    }

    i64 ans = dp[0][N-1];

    PRINTLN(ans);

    vector<Move> trace;
    trace.reserve(N);
    for(i64 l=0, r=N-1; l <= r; ) {
        Move mv = moves[l][r];
        trace.emplace_back(mv);
        switch(mv) {
        case Move::L:
            ++l;
            break;
        case Move::R:
            --r;
            break;
        }
    }
    DBG(trace);

    {
        i64 score[2] {};
        ModPT<2> turn = 0;
        i64 l = 0;
        i64 r = N-1;
        for(Move mv : trace) {
            switch(mv) {
            case Move::L:
                score[i64(turn)] += A[l];
                ++l;
                break;
            case Move::R:
                score[i64(turn)] += A[r];
                --r;
                break;
            }
            ++turn;
        }
        DBG_CARRAY(score);
        assert(score[0]-score[1] == ans);
    }
}

signed main() {
    

    solve();

    EXIT();
}
