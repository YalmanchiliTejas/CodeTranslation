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

int main() {
    int n;
    cin >> n;
    auto h = vector<int>(n);
    for (auto& h_i : h)
        cin >> h_i;

    auto h_max = 0;
    auto cnt = 0;
    for (auto h_i : h) {
        if (h_i >= h_max)
            cnt++;
        h_max = max(h_max, h_i);
    }

    cout << cnt << endl;
    return 0;
}
