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
#include <cmath>

using namespace std;

template<class T>
class Input {
public:
    T operator()() const {
        T v;
        cin >> v;
        return v;
    }
};

template<class U>
class Input<vector<U>> {
public:
    vector<U> operator()() const {
        Input<size_t> in{};
        auto n = in();
        return (*this)(n);
    }
    vector<U> operator()(size_t n) const {
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

template<class T>
T input() {
    Input<T> i{};
    return i();
}

int main() {
    Input<size_t> in{};
    auto a = in();
    auto b = in();
    auto c = in();
    auto x = in();
    auto y = in();
    size_t d = 0;
    if (2 * c < a + b) {
        auto z = min(x, y);
        x -= z;
        y -= z;
        d += 2 * c * z;
    }
    d += min(a * x + b * y, 2 * c * max(x, y));
    cout << d << endl;
    return 0;
}
