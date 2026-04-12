#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

long long lcm(long long x, long long y)
{
    if (x == 0 || y == 0)
        return 0;
    return x / gcd(x, y) * y;
}

int main()
{
    string s;
    cin >> s;
    const string ss = "AC";
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (ss == s.substr(i, 2))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
