#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

_LL getans(_LL n, _LL ox, _LL m, int *index)
{
    _LL sum = 0;
    _LL x = ox;
    vector<_LL> ans(m);
    for(_LL i = 1; i < n; i++ )
    {
        x = (x * x) % m;
        if( index[x] >= 0 )
        {
            int si = index[x];
            _LL looplen = i - si;
            _LL loopv = sum - ans[si];
            _LL looptime = (n - si) / looplen;
            _LL loopmod = (n - si) % looplen;
            return ox + ans[si] + loopv * looptime + (ans[si + loopmod] - ans[si]);
        } 
        else
        {
            ans[i] = sum;
            sum += x;
            index[x] = i;
        }
    }
    return sum + ox;
}

int main()
{
    _LL n, x, m; cin >> n >> x >> m;
    int *index = new int[m];
    rep(i, m) index[i] = -1;
    cout << getans(n, x, m, index) << endl;
    delete index;
    return 0;    
}