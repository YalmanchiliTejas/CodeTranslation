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
constexpr int M = 1'000'000'007;

int main()
{
    int n;
    cin >> n;
    auto a = vector<large>(n);
    for (auto& a_i : a) {
        cin >> a_i;
    }
    auto a_sum = vector<large>(n + 1);
    a_sum[0] = 0;
    for (auto i = 0; i < n; ++i) {
        a_sum[i + 1] = a_sum[i] + a[i];
    }

    auto sum = 0LL;
    for (int i = 0; i < n-1; ++i) {
        auto tmp = (a_sum[n] - a_sum[i+1]) % M;
        sum += a[i] * tmp % M;
        sum %= M;
    }
    cout << sum << endl;
    return 0;
}