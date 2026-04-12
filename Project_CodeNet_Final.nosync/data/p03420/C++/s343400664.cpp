#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int inf = 1e9 + 7;
LL n, k;

int main()
{
    while(~scanf("%lld %lld", &n, &k))
    {
        LL sum = 0;
        if(k == 0)
        {
            cout << n * n << endl;
            continue;
        }
        for(LL i = k + 1; i <= n; ++i)
        {
            sum += (i - k) * (n / i);
            if(n % i >= k) sum += n % i - k + 1;
        }
        cout << sum << endl;
    }
}
