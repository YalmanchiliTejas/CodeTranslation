#include <iostream>
#include <stdio.h>
using namespace std;
const int mod = 1e9 + 7;
int a[200005];
long long sum[200005];
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sum[0] = a[n];
    //cout << sum[0] << endl;
    for (int i = 1; i < n; i++)
    {

        sum[i] = (sum[i - 1] + a[n - i])%mod;
        //cout << sum[i] << endl;
    }
    long long ans = 0;
    for (int i = 1; i < n ; i++)
    {
        ans = ans + (a[i] * sum[n - i - 1] % mod);
        //cout << a[i] <<" "<< sum[n-i-1] << endl;
        ans %= mod;
    }
    printf("%lld\n", ans%mod);
}