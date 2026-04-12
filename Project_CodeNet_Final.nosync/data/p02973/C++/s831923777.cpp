#include <algorithm>
#include <iostream>
#include <vector>

namespace multiset
{

class multiset
{
  private:
    std::vector<int> tree;
    int MSB;

    void add(int i, int x)
    {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += x;
        }
    }

    int sum(int i)
    {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res += tree[i];
        }
        return res;
    }

    int bisect(int w)
    {
        int i = 0;
        for (int k = MSB; k > 0; k /= 2) {
            if (i + k < tree.size() && tree[i + k] < w) {
                w -= tree[i + k];
                i += k;
            }
        }
        return i + 1;
    }

    uint32_t get_MSB(uint32_t x)
    {
        return 0x80000000 >> __builtin_clz(x);
    }

  public:
    multiset(int N) : tree(N + 1), MSB(get_MSB(N)) {}
    void insert(int x) { add(x, 1); }
    void erase(int x) { add(x, -1); }
    int lower_bound(int x)
    {
        int s = sum(x);
        return (s == 0) ? 0 : bisect(s);
    }

    size_t size() { return sum(tree.size() - 1); }
};

} // namespace multiset

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (auto &&a : A) {
        std::cin >> a;
    }

    std::vector<int> B = A;
    std::sort(begin(B), end(B));
    B.erase(std::unique(begin(B), end(B)), end(B));

    std::transform(begin(A), end(A), begin(A), [&](int val) -> int {
        return std::lower_bound(begin(B), end(B), val) - begin(B) + 1;
    });

    multiset::multiset ms(B.size());
    for (auto a : A) {
        auto i = ms.lower_bound(a - 1);
        if (i != 0) {
            ms.erase(i);
        }
        ms.insert(a);
    }

    std::cout << ms.size() << '\n';
}
