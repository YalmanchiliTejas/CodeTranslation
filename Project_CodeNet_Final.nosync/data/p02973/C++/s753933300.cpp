#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

template <typename T> class segtree
{
private:
    std::size_t N;
    std::vector<T> data;

    T query(std::size_t a, std::size_t b, std::size_t k, std::size_t l, std::size_t r)
    {
        if (r <= a || b <= l)
        {
            return std::numeric_limits<T>::min();
        }
        if (a <= l && r <= b)
        {
            return data[k];
        }
        size_t m = (l + r) / 2;
        return std::max(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
    }

public:
    segtree(const std::size_t n, const T init)
    {
        N = 1;
        while (N < n)
        {
            N *= 2;
        }
        data.resize(N * 2, init);
    }

    void update(std::size_t k, T a)
    {
        k += N - 1;
        data[k] = a;
        while (k > 0)
        {
            k = (k - 1) / 2;
            data[k] = std::max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    T query(std::size_t a, std::size_t b) { return query(a, b, 0, 0, N); }
};

int main()
{
    int n;
    cin >> n;
    segtree<int64_t> tree(n, 0);

    vector<pair<int64_t, int>> vs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vs[i].first;
        vs[i].second = i;
    }
    sort(vs.begin(), vs.end(), [&](const pair<int64_t, int>& p1, const pair<int64_t, int>& p2) {
        if (p1.first != p2.first)
        {
            return p1.first > p2.first;
        }
        else
        {
            return p1.second < p2.second;
        }
    });

    for (auto& v : vs)
    {
        const int count = tree.query(0, v.second);
        tree.update(v.second, count + 1);
    }
    cout << tree.query(0, n) << endl;
}