#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

#define big (1000000007)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long s[n], sum[n] = {0};
    long long ans = 0;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sum[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
        sum[i] = (long long)sum[i + 1] + s[i];
    for (int i = 0; i < n - 1; i++)
    {
        ans = (ans + ((sum[i + 1])%big * (s[i]%big)) % big) % big;
    }
    cout << ans;
}