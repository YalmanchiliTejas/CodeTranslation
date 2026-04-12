#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

long long int MAXM = 1e9 + 7;

void solve()
{
    long long int ans = 0;
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> prefix(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    prefix[0] = a[0];
    for (long long int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    for (long long int i = 1; i < n; i++)
    {
        long long int val = (a[i] * (prefix[i - 1]%MAXM))%MAXM;
        ans += val;
        ans %= MAXM;
    }

    ans %= MAXM;
    
    cout << ans << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    solve();


    return 0;
}
