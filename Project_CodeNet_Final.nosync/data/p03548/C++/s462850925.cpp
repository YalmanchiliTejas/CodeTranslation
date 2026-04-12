#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
const int maxn = 100005;
using namespace std;

int main()
{
    ll x,y,z;
    cin >> x >> y >> z;
    double sum = x - z;
    ll ans;
    sum = sum /  (y + z);
    ans = (int )sum;
    cout << ans << endl;
    return 0;
}
