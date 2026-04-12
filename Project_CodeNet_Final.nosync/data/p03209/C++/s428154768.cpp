#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> sizes(N+1);
    vector<long long> patties(N+1);
    sizes[0] = 1;
    patties[0] = 1;
    for (int i = 1; i <= N; ++i) {
        sizes[i] = 2*sizes[i-1] + 3;
        patties[i] = 2*patties[i-1] + 1;
    }
    function<long long (int, long long)> count_patties = [&](int n, long long x) {
        if (n == 0) {
            assert (0 <= x && x <= 1);
            return (long long) (x == 1);
        }
        if (x == 1) {
            return 0LL;
        }
        if (x <= 1 + sizes[n-1]) {
            return count_patties(n-1, x-1);
        }
        if (x == 2 + sizes[n-1]) {
            return patties[n-1] + 1;
        }
        if (x <= 2 + 2*sizes[n-1]) {
            return patties[n-1] + 1 + count_patties(n-1, x - 2 - sizes[n-1]);
        }
        assert(x == 3 + 2*sizes[n-1]);
        return patties[n];
    };
    cout << count_patties(N, X) << endl;
    return 0;
}
