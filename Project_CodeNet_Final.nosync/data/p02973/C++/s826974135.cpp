// Author: πα

#include <bits/stdc++.h>
using namespace std;
#define long int64_t

const int N = 1e5 + 5;
int a[N], m;
const int INF = (1LL << 30) - 1;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, i, d;
    cin >> n;
    for(i = 0; i < n; ++i)
    {
        cin >> d;
        d = -d;
        int idx = upper_bound(a, a+m, d) - a;
        if(idx == m)
            m++;
        a[idx] = d;
    }
    cout << m;
    return 0;
}
