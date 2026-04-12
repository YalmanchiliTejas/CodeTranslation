#include<bits/stdc++.h>
#define pb push_back

#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
#define mod 1000000007
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0, ans = 0;
    cin >> n;
    int arr[n];
    int suffix[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        sum += arr[i];
        suffix[i] = sum;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int r = suffix[i + 1];
        ans += ((r % mod) * (arr[i] % mod)) % mod;
    }
    cout << ans % mod << endl;
    return 0;
}
