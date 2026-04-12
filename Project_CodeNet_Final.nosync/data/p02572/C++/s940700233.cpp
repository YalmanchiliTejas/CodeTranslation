#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
    long long n, p = 0;
    cin >> n;
    long long a[n], s[n - 1];
    cin >> a[0];
    s[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        s[i] %= mod;
    }
    for (int i = 0; i < n - 1; i++)
    {
        p += s[i] * a[i + 1];
        p %= mod;
    }
    cout << p;
}