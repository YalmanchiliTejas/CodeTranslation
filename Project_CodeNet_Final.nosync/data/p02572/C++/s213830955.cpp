#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
#define mk make_pair
#define P pair<int,int>
#define ll  long long
__int128 a[N],sum[N];
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        sum[i] = sum[i-1] + a[i];
        sum[i] = sum[i] % mod;
    }
    __int128 ans = 0;
    for(int i=1;i<n;i++)
    {
        ans += a[i] * (sum[n] - sum[i]+mod) % mod;
        ans %= mod;
    }
    cout << (ll)ans % mod << "\n";

    return 0;
}
