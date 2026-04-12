#include <bits/stdc++.h>

using namespace std;

const int Nmax = 55;

typedef long long ll;
ll sum, need, total, j, a[Nmax];
int n, i;

int main()
{
  //  freopen("input", "r", stdin);
  //  freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<=n; ++i) cin >> a[i], sum += a[i];

    for(j = sum - n*(n-1); j<=sum; ++j)
    {
        total = 0;
        for(i=1; i<=n; ++i)
        {
            need = a[i] + j - (n-1);
            if(need < 0) continue;
            if(need % (n+1) == 0) need /= (n+1);
                else need = need / (n+1) + 1;
            total += need;
        }

        if(total <= j) break;
    }

    cout << j << '\n';

    return 0;
}
