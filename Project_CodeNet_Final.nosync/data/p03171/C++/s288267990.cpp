#include <iostream>
#include <cstdio>
using namespace std;

const long long oo = 1e15;
long long a[3005];
bool c[3005][3005];
long long f[3005][3005];
int n;

void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

///t == 1 -> maximizing (X - Y) and vice versa
long long tryyy(int t,int l,int r)
{
    if (l > r) return 0;
    if (c[l][r]) return f[l][r];
    long long tmp;
    if (t == 1)
    {
        tmp = tryyy(1-t, l , r - 1) + a[r];
        tmp = max(tmp, tryyy(1-t, l + 1, r) + a[l]);
    }
    else
    {
        tmp = tryyy(1 - t, l, r - 1) - a[r];
        tmp = min(tmp , tryyy(1-t, l + 1, r) - a[l]);
    }
    c[l][r] = true;
    f[l][r] = tmp;
    return tmp;
}


int main()
{
    //freopen("file.inp","r",stdin);
    inp();
    cout << tryyy(1,1,n);
    return 0;
}
