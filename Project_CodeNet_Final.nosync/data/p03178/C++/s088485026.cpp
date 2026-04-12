#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long mod = 1e9+7;
int n,m;
int d;
string s;
long long f[2][10005][105];
bool c[2][10005][105];


void inp()
{
    cin >> s;
    n = s.size();
    cin >> d;
}


long long tryyy(int t, int p, int m)
{
    if (p == n)
    {
        if (m == 0) return 1;
        else return 0;
    }
    if (c[t][p][m]) return f[t][p][m];
    long long tmp = 0;
    if (t == 1)
    {
        int x = s[p] - '0';
        tmp = tryyy(1,p+1,(m+x)%d);
        for (int i = 0; i < x; i++)
        tmp = (tmp + tryyy(0, p + 1, (m+i)%d))%mod;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        tmp = (tmp + tryyy(0,p+1,(m+i)%d))%mod;
    }
    c[t][p][m] = true;
    f[t][p][m] = tmp;
    return tmp;
}


void proc()
{
    long long ans = tryyy(1,0,0);
    if (ans == 0)
    {
        ans = mod-1;
    }
    else ans--;
    cout << ans;
}



int main()
{
    inp();
    proc();
    return 0;
}
