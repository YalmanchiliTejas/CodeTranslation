#include <numeric>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long a[50]; for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = accumulate(a, a+n, 0LL);
    long long k = max(0LL, sum - n * (n-1));
    while (true) {
        long long s = 0;
        for (int i=0; i<n; i++) {
            long long r = (a[i] + k + 1) / (n + 1);
            if (r == (a[i] + k) / (n + 1)) s += r;
            else { s = -1; break; }
        }
        if (s == k) { cout << s << endl; return 0; }
        k++;
    }
}
