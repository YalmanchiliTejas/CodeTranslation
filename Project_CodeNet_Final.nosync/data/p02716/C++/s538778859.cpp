#include <iostream>
#include <algorithm>
using namespace std;


long best_half(int* a, long* calculated, int jumps, int i, int n) {
    if (i >= n)
        return 0;
    else if (calculated[3 * i + jumps] != -1)
        return calculated[3 * i + jumps];
    else {
        long result = best_half(a, calculated, jumps, i + 2, n);
        if (jumps < 2)
            result = max(result, best_half(a, calculated, jumps + 1, i + 3, n));
        if (jumps == 0)
            result = max(result, best_half(a, calculated, jumps + 2, i + 4, n));
        calculated[3 * i + jumps] = a[i] + result;
        return calculated[3 * i + jumps];
    }
}

int main() {
    int n;
    cin >> n;
    int* a = (int*) malloc(sizeof(int) * n);
    long* calculated = (long*) malloc(sizeof(long) * 3 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 3 * n; i++)
        calculated[i] = -1;
    if (n % 2 == 0)
        cout << max(best_half(a, calculated, 1, 0, n), best_half(a, calculated, 2, 1, n));
    else
        cout << max(max(best_half(a, calculated, 0, 0, n), best_half(a, calculated, 1, 1, n)), best_half(a, calculated, 2, 2, n));
    return 0;
}