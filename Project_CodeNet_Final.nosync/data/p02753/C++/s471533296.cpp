#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <limits>
#include <numeric>
#include <cmath>

using namespace std;

template<class T>
class Input {
public:
    auto operator()() const {
        T v;
        cin >> v;
        return v;
    }
};

template<class L, class R>
class Input<pair<L, R>> {
public:
    auto operator()() const {
        L l;
        R r;
        cin >> l >> r;
        return make_pair(l, r);
    }
};

template<class U>
class Input<vector<U>> {
public:
    auto operator()() const {
        Input<size_t> in{};
        auto n = in();
        return (*this)(n);
    }
    auto operator()(size_t n) const {
        vector<U> v;
        v.reserve(n);
        Input<U> in{};
        for (size_t i = 0; i < n; ++i) {
            auto u = in();
            v.emplace_back(move(u));
        }
        return v;
    }
};

template<class U>
class Input<vector<vector<U>>> {
public:
    auto operator()() const {
        Input<size_t> in{};
        auto n = in();
        auto m = in();
        return (*this)(n, m);
    }
    auto operator()(size_t n, size_t m) const {
        vector<vector<U>> v;
        v.reserve(n);
        Input<vector<U>> in{};
        for (size_t i = 0; i < n; ++i) {
            auto u = in(m);
            v.emplace_back(move(u));
        }
        return v;
    }
};

class InputType
{
public:
    template<class T>
    operator T() const {
        Input<T> i{};
        return i();
    }
};

auto input() {
    return InputType();
}

size_t bitcount(size_t n) {
    size_t c = 0;
    while (n) {
        if (n & 1ull)
            ++c;
        n >>= 1;
    }
    return c;
}

auto make_order(size_t n) {
    vector<size_t> a(n, 0);
    iota(begin(a), end(a), 0);
    return a;
}

template<class T>
auto next_permutation(T&& x) {
    using std::begin;
    using std::end;
    return next_permutation(begin(x), end(x));
}

using ll = long long;
using ull = unsigned long long;

int main() {
    string s = input();
    if (s[0] == s[1] && s[1] == s[2])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
