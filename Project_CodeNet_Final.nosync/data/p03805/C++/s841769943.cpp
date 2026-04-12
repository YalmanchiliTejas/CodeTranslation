#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<std::pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }

    int sum = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            if (std::find_if(a.begin(), a.end(), [&](const auto& x) {
                    if ((x.first == v[i] || x.first == v[i + 1]) &&
                        (x.second == v[i] || x.second == v[i + 1]))
                        return true;
                    else
                        return false;
                }) == a.end())
                goto LAST;
        }
        sum++;
    LAST:
        continue;
    } while (std::next_permutation(v.begin() + 1, v.end()));

    cout << sum << endl;
}