#include "math.h"
#include <set>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
int main()
{
    int n;
    cin >> n;
    int a[200005], p[200005] = {};
    rep(i, n) p[i] = i;
    rep(i, n)
    {
        cin >> a[i];
    }
    int start = n / 2;
    rep(i, n)
    {
        start = start + (i & 1 ? -1 : 1) * i;
        p[start] = i;
    }
    if (n & 1)
        reverse(p, p + n);
    /*rep(i, n)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    */
    rep(i, n)
    {
        cout << a[p[i]] << " ";
    }
    cout << endl;
}
