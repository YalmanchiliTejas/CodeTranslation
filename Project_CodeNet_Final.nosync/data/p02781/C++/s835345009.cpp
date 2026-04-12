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

int64_t comb(int64_t N, int64_t R)
{
    if (R < 0 || R > N)
        return 0;
    if (R == 1)
        return N;
    else if (R == 2)
        return N * (N - 1) / 2;
    else
        return N * (N - 1) * (N - 2) / 6;
}

int64_t pow(int64_t N, int64_t k)
{
    int64_t res = 1;
    for (int i = 0; i < k; ++i)
        res *= N;
    return res;
}

int64_t solve(string& n, int i, int k, bool smaller)
{
    if (k == 0)
    {
        return 1;
    }
    if (i == n.size())
    {
        return 0;
    }

    if (smaller)
    {
        return comb(n.size() - i, k) * pow(9, k);
    }
    else
    {
        if (n[i] == '0')
        {
            return solve(n, i + 1, k, false);
        }
        else
        {
            auto zero = solve(n, i + 1, k, true);
            auto mid = solve(n, i + 1, k - 1, true) * (n[i] - '1');
            auto same = solve(n, i + 1, k - 1, false);
            return zero + mid + same;
        }
    }
}

int main()
{
    string n;
    cin >> n;
    int k;
    cin >> k;

    cout << solve(n, 0, k, false) << endl;
}
