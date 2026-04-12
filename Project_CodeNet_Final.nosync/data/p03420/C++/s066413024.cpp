#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

long long n, ans = 0, k;

int main()
{
    cin >> n >> k;
    if(k == 0)
    {
        cout << n * n;
        return 0;
    }

    for(long long i = k + 1; i <= n; i++)
    {
        ans += (n / i) * (i - k);
        if(n % i >= k)
        {
            ans += ((n % i) - k + 1);
        }
    }

    cout << ans;
    return 0;
}
