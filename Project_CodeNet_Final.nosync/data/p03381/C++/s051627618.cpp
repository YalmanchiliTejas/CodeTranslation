#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
#define loop(i, a, b) for (int i = (a), i##len = (b); i < i##len; ++i)
#define rep(i, n) loop(i, 0, n)
#define lin long long

int n;
lin x[200001];
lin a[200001];

int main(void)
{
    cin >> n;
    rep(i,n)
    {
        cin >> x[i];
        a[i] = x[i];
    }

    sort(x, x + n);

    lin m1 = x[n / 2 - 1];
    lin m2 = x[n / 2];

    rep(i, n)
    {
        lin result = a[i] <= m1 ? m2 : m1;
        cout << result << endl;
    }

    return 0;
}
