#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
using pi = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    ll a[n+2], b = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b += a[i];
        b %= MOD;
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        b -= a[i];
        if(b < 0) b += MOD;

        sum += a[i]*b;
        sum %= MOD;
    }
    cout << sum << endl;
}
