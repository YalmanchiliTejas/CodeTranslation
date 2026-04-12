#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

_LL combination(_LL n, _LL r)
{
    _LL ret = 1;
    rep(i, r) ret = (ret * ( n - i )) / (i + 1); 
    return ret;
}

_LL getans(_LL *n, _LL k, int l)
{
    if( k > l ) return 0;
    if( l <= 0 ) return 1;
    if( k == 0 ) return 1;
    if( n[0] == 0 )  return getans( n + 1, k, l - 1);

    _LL k9m = 1;
    rep(i, k -1) k9m *= 9;
    _LL k9 = k9m * 9;
    return combination(l - 1, k) * k9 + (n[0] - 1) * combination(l - 1, k - 1) * k9m + getans(n + 1, k - 1, l - 1);
}

int main()
{
    string s;
    _LL k;
    cin >> s >> k;
   _LL *n = new _LL[s.length()];
    rep(i, s.length()) n[i] = s[i] - '0';
    cout << getans(n, k, s.length());
    delete n;
    return 0;    
}