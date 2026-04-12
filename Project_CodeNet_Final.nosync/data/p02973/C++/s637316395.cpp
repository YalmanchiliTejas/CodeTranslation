#include <bits/stdc++.h>
using i64 = long long;

template <class T = long long int>
class Bit {
    private:
    int len;
    T *arr;
    T init;

    public:
    Bit(int length, T initialValue = 0) : len(length), init(initialValue) {
        arr = new T[length + 1];
        for (int i = 0; i <= length; i++) {
            arr[i] = initialValue;
        }
    }
    ~Bit() {
        delete[] arr;
    }
    void update(int a, T newval) {
        for (int x = a; x <= len; x += x & -x) arr[x] = ((arr[x] > newval) ? arr[x] : newval);
    }
    T query(int a) const {
        T ret = init;
        for (int x = a; x > 0; x -= x & -x) ret = ((arr[x] > ret) ? arr[x] : ret);
        return ret;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;
    std::reverse(a.begin(), a.end());

    auto b(a);
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (auto &e : a) e = std::lower_bound(b.begin(), b.end(), e) - b.begin() + 1;

    std::vector<int> dp(n);
    Bit<> bit(n + 10);
    dp[0] = 1;
    bit.update(a[0], 1);
    for (int i = 1; i < n; i++) {
        dp[i] = std::max(1ll, bit.query(a[i]) + 1);
        bit.update(a[i], dp[i]);
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;

    return 0;
}
