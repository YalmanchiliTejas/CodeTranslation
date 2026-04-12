#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll a[N];
ll sum[N];
ll f[N];
int main()
{
    memset(sum, 0, sizeof sum);
    memset(f, 0, sizeof f);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i > 1)
            sum[i] = sum[i - 2] + a[i];
        else
            sum[i] = a[i];
    }
    for(int i = 2; i <= n; i++)
    {
        if(i & 1)
            f[i] = max(f[i - 2] + a[i], f[i - 1]);
        else
            f[i] = max(f[i - 2] + a[i], sum[i - 1]);
    }
    cout << f[n] << endl;
    return 0;
}
