#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int n = 100 * r + 10 * g + b;
    cout << ((n%4==0)?"YES":"NO") << "\n";

    return 0;
}
