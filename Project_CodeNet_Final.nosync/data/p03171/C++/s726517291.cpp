/** https://atcoder.jp/contests/dp/tasks/dp_l */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long a[3003], f[3003][3003], s[3003];
#define sum(l, r) (s[r] - s[l-1])

int main()
{
    cin >> n;
    for(int i = 1; i<= n; i++) cin >> a[i];

    for(int i = 0; i<= n; i++) for(int j = 0; j<= n; j++) f[i][j] = 0;

    s[0] = 0;
    for(int i = 1; i<= n; i++) f[i][i]= a[i], s[i] = s[i-1] + a[i];

    for(int l = n-1; l>0; l--)
    for(int r = l+1; r<=n; r++)
        f[l][r] = sum(l, r) - min(+ f[l+1][r], f[l][r-1] );

    cout << 2ll*f[1][n] - sum(1, n);

    return 0;
}

