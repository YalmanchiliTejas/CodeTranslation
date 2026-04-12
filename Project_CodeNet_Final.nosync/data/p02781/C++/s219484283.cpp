#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int nines[1000];

unsigned long long solve(const int *const n, const int width, const int k) {
    assert(width >= 1);
    assert(k >= 0);
    assert(0 <= *n && *n <= 9);
    if (k > width)
        return 0;
    if (k == 0)
        return 1;
    if (width == 1)
        return *n;
    if (*n == 0)
        return solve(n + 1, width - 1, k);

    auto counter = 0ULL;

    counter += solve(n + 1, width - 1, k - 1);
    counter += (*n - 1) * solve(nines, width - 1, k - 1);
    counter += solve(nines, width - 1, k);

    return counter;
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    auto x = vector<int>(n.length());
    auto index = 0;
    for (auto c : n)
        x[index++] = c - '0';

    for (auto &nine : nines)
        nine = 9;
    cout << solve(x.data(), x.size(), k);
    return 0;
}
