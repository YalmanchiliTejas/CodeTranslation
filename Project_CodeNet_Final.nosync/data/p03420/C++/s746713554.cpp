#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    long long int fans = 0;
    for(int i = 1; i <= n; i++) //b
    {
        int cur = i;
        int times = n / i;
        int left = n % i;
        int get = max(0,i - k);
        fans += get * 1ll * times;
        if(!k)
        fans--;
        fans += max(0,left - k + 1);
    }
    printf("%lld\n",fans);
    return 0;
}
