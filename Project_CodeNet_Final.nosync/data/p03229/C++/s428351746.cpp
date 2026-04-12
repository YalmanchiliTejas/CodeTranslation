#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define MAXN 100000


long long a[MAXN + 1];
long long rez[MAXN + 3];
int main() {
    long long n;
    long long ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    long long p;
    bool ok = 0;
    if (n % 2 != 0) {
        ok = 1;
        p = a[n / 2 + 1];
        for (int i = n / 2 + 1; i < n; i++)
            a[i] = a[i + 1];
        n--;
    }
    int ind1 = n / 2;
    int ind2 = n / 2;
    bool l = 0;
    rez[n / 2] = a[1];
    for (int i = 2; i <= n / 2; i++) {
        if (l == 0) {
            ind1 = ind1 + 2;
            rez[ind1] = a[i];
        }
        else {
            ind2 = ind2 - 2;
            rez[ind2] = a[i];
        }
        l = 1 - l;
    }
    rez [n / 2 + 1] = a[n];
    ind1 = n / 2 + 1;
    ind2 = n / 2 + 1;
    l = 0;
    for (int i = n - 1; i >= n / 2 + 1; i--) {
        if (l == 0) {
            ind1 = ind1 - 2;
            rez[ind1] = a[i];
        }
        else {
            ind2 = ind2 + 2;
            rez[ind2] = a[i];
        }
        l = 1 - l;
    }
    if (ok == 1) {
        if(abs(p - rez[1]) < abs(p - rez[n])) {
            rez[n + 1] = p;
            for (int i = 1; i <= n; i++) {
                ans += abs(rez[i] - rez[i + 1]);
            }
        }
        else {
            rez[0] = p;
            for (int i = 0; i <= n - 1; i++) {
                ans += abs(rez[i] - rez[i + 1]);
            }
        }
    }
    else {
        for (int i = 1; i <= n - 1; i++) {
            ans += abs(rez[i] - rez[i + 1]);
        }
    }
    std::cout << ans;
}
