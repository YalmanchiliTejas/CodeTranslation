#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> lis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lis.at(i);
    }
    int mod = 1000000007;
    long long ans = 0;

    long long sum = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        sum = (sum + lis.at(i + 1)) % mod;
        ans = (ans + lis.at(i) * sum) % mod;
    }
    cout << ans << endl;
}