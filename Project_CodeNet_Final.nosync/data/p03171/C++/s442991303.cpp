#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli n, i, j, size, l, r, rv, lv;
    
    cin >> n;
    
    lli a[n];
    lli maximize[n][n];
    
    for(i = 0; i < n; ++i)
    {
        cin >> a[i];
        maximize[i][i] = a[i];
    }
    
    lli INF = 1e18;

    //cout << INF << '\n';
    
    
    
    /*
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            maximize[i][j] = -INF;
        }
    }
    */
    
    
    
    for(size = 2; size <= n; ++size)
    {
        for(l = 0; l < n - size + 1; ++l)
        {
            r = l + size - 1;
            lv = a[l] - maximize[l + 1][r];
            rv = a[r] - maximize[l][r - 1];
            maximize[l][r] = max(lv, rv);
        }
    }
    /*
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            cout << maximize[i][j] << " ";
        }
        cout << '\n';
    }
    
    
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            cout << minimize[i][j] << " ";
        }
        cout << '\n';
    }
    */
    
    cout << maximize[0][n - 1];
    
    return 0;
}