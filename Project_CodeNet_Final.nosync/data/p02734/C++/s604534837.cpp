#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3030;
const int Mod = 998244353;

int a[N];
int Dp[N][N];

void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}

void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += Mod;
}

int add(int x, int y)
{
    return add_self(x, y), x;
}

int sub(int x, int y)
{
    return sub_self(x, y), x;
}

int mul(int x, int y)
{
    return (ll) x * y % Mod;
}

int Rec(int i, int Sum)
{
    if(Sum < 0) return 0;
    if(!Sum)    return i + 1;
    if(i == 0)  return 0;

    if(Dp[i][Sum] + 1)  return Dp[i][Sum];

    return Dp[i][Sum] = add(Rec(i - 1, Sum), Rec(i - 1, Sum - a[i]));
}

int main()
{
    memset(Dp, -1, sizeof(Dp));

    int n, s;   cin >> n >> s;

    for(int i = 1; i <= n; i++) scanf("%d", a + i);

    int Ans = 0;

    for(int i = n; i > 0; i--)
        add_self(Ans, Rec(i, s));

    cout << Ans << endl;
}
