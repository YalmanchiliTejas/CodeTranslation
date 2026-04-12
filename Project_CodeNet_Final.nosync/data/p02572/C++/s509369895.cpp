#include <bits/stdc++.h>
using namespace std;
using s64 = signed long long;
using u64 = unsigned long long;
using f128 = long double;

int main()
{
    s64 n;
    cin >> n;
    vector<u64> a(n);
    for(s64 i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    u64 sum = 0;
    u64 jSum = 0;
    u64 div = pow(10, 9) + 7;
    for(s64 i = n - 2; i >= 0; i--)
    {
        s64 j = i + 1;
        jSum += a[j];
        jSum %= div;
        sum += a[i] * jSum;
        sum %= div;
    }

    cout << sum << endl;

    return 0;
}
