#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int64_t solve(const vector<int64_t>& as)
{
    const auto n = as.size();
    vector<int64_t> bs(n);

    for (int i = 0; i < n / 2; i++)
    {
        bs[2 * i] = as[i + n / 2];
        bs[2 * i + 1] = as[i];
    }
    if (n % 2 == 1)
    {
        bs[n - 1] = as[n - 1];
        // as[0:n/2], as[n/2:n]
        swap(bs[2], bs[n - 1]);
    }

    int64_t sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(bs[i] - bs[i + 1]);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int64_t> as(n);
    for (auto& a : as)
    {
        cin >> a;
    }
    sort(as.begin(), as.end());
    auto sum1 = solve(as);
    reverse(as.begin(), as.end());
    auto sum2 = solve(as);

    cout << max(sum1, sum2) << endl;
}
