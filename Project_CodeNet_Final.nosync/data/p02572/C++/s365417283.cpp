#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int n;
long long sum = 0;
const long long Mod = 1e9 + 7;
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        ans += x * sum;
        ans %= Mod;
        sum += x;
        sum %= Mod;
    }
    cout << ans;
    return 0;
}