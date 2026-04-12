#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int a[200'000];

int main()
{
    large n;
    int x, m;
    cin >> n >> x >> m;

    auto s = unordered_map<int, int>();
    auto loop_begin = 0;
    auto loop_size = 0;
    a[0] = x;
    s.emplace(a[0], 0);
    for (int i = 1;; ++i) {
        a[i] = large(a[i - 1]) * a[i - 1] % m;
        auto [itr, inserted] = s.emplace(a[i], i);
        if (!inserted) {
            loop_begin = itr->second;
            loop_size = i - itr->second;
            cerr << "found " << a[i] << "\n";
            break;
        }
    }

    auto cnt = n;
    auto sum = 0LL;
    for (int i = 0; i < min(large(loop_begin), n); ++i) {
        sum += a[i];
    }
    cnt -= min(large(loop_begin), n);

    auto loop_sum = 0LL;
    for (int i = loop_begin; i < loop_begin + loop_size; ++i) {
        loop_sum += a[i];
    }
    auto loop_count = cnt / loop_size;
    sum += loop_count * loop_sum;
    cnt -= loop_count * loop_size;
    for (int i = loop_begin; i < loop_begin + cnt; ++i) {
        sum += a[i];
    }

    cout << sum << endl;
    return 0;
}
