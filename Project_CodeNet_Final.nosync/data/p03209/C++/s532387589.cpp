#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> a;
vector<long long> p;

long long f(long long n, long long x) {
    if (n == 0) {
        if (x <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (x <= 1 + a[n - 1]) {
        return f(n - 1, x - 1);
    } else {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }
}
int main() {
    long long n, x;
    cin >> n >> x;
    a.push_back(1);
    p.push_back(1);
    for (long long i = 0; i < n; i++) {
        a.push_back(a[i] * 2 + 3);
        p.push_back(p[i] * 2 + 1);
    }

    cout << f(n, x) << endl;
    return 0;
}