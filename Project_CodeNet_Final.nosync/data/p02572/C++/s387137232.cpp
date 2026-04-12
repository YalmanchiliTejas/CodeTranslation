#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
signed main() {
    int n;
    cin >> n;
    int sum = 0, sumsq = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        sum = (sum + x)%mod;
        sumsq = (sumsq + x*x)%mod;
    }
    sum = (sum*sum)%mod;
    sum = (sum - sumsq)%mod;
    sum = sum*500000004%mod;
    sum = (sum+mod)%mod;
    cout << sum;
}