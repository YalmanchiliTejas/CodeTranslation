#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr double pi = acos(-1);

int main()
{
    double a, b;
    cin >> a >> b;
    double ans = a * b / (a + b);
    cout << fixed << setprecision(10);
    cout << ans << endl;
}

