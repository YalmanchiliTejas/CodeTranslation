#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
}

int main(void)
{
    lli N;
    cin >> N;
    lli a[N];
    lli b[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    fill(b, b + N + 1, 0);
    lli ans = 0;
    lli m = 1000000007;
    for (int i = 1; i <= N; i++)
    {
        b[i] = b[i - 1] + a[i - 1];
        b[i] %= m;
    }
    for (int i = 1; i < N; i++)
    {
        lli tmp = a[i - 1] * (b[N] + m - b[i]);
        tmp %= m;
        ans += tmp;
        ans %= m;
    }
    cout << ans << endl;
    return 0;
}
