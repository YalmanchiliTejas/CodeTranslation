#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = (x % M);
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, int n)
{
    if (n == 0)
        return ban(1);
    if (n % 2 == 0)
    {
        ban y = ast(x, n / 2);
        return y * y;
    }
    else
    {
        ban y = ast(x, n - 1);
        return x * y;
    }
}
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}
ban gum(int x)
{
    return ban((x + 1) * 1LL * x / 2);
}

int n, m, k;

int main()
{
    cin >> n >> m >> k;

    ban z(1);
    for (int i = n * m - 2, j = k - 2; j > 0; --i, --j)
        z = z * ban(i);
    for (int i = 1; i <= k - 2; ++i)
        z = z / ban(i);

    ban ans;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ban x = gum(i - 1) + gum(n - i);
            ban y = gum(j - 1) + gum(m - j);
            ans = ans + x * ban(m) + y * ban(n);
        }
    }
    ans = ans / ban(2);
    ans = ans * z;
    cout << ans.x << endl;
    return 0;
}
