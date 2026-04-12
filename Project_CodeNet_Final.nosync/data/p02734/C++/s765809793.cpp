#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int g_bm = 998244353;

int modl(_LL a)
{
    a %= g_bm;
    if( a < 0 ) a += g_bm * ( 1 - (a + 1) / g_bm );
    return a;
}

int modadd(_LL a, _LL b)
{
    return modl(a + b);
}

int modminus(_LL a, _LL b)
{
    return modl(a - b);
}

int modmul(_LL a, _LL b)
{
    return modl(a * b);    
}


int main()
{
    int n, s;
    cin >> n >> s;
    int *cnt = new int[s];
    int *next = new int[s];
    int *a = new int[n];
    rep(i, n) cin >> a[i];

    int ans = 0;

    rep(i, n)
    {
        if( a[i] > s ) continue;
        if( a[i] == s )
        {
            ans = modadd( ans, modmul(i + 1, n - i));
            continue;
        }
        ans = modadd(ans, modmul(cnt[s - a[i]], n - i));

        int ruiseki = 0;
    
        rep(j, s - a[i])
        {
            if( j == 0 ) 
            {
                next[a[i] + j] = i + 1;
            }
            else
            {
                next[a[i] + j] = cnt[j];
            }
        }
        rep(j, s - a[i]) cnt[a[i] + j] = modadd(cnt[a[i] + j], next[a[i] + j]);
    }

    cout << ans;
}