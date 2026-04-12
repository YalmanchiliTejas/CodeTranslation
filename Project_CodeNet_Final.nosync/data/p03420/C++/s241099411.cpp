#include <iostream>

using namespace std;

int
main()
{
    long long n, k;
    cin >> n >> k;

    long long count = 0;
    if (k == 0) {
        count = n * n;
    } else {
        for (long long b = 1; b <= n; b++) {
            if (b <= k)
                continue;
            count += (n / b) * (b - k);
            if (n % b >= k)
                count += n % b - k + 1;
        }
    }
    cout << count << endl;
}
