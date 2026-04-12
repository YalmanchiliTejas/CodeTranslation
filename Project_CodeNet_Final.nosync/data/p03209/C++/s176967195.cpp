#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll L[51], P[51];
ll dfs(ll n, ll x)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    ll ans = 0;
    if(x==1){
        return 0;
    }
    else if (x <= L[n - 1] + 1)
    {
        ans += dfs(n - 1, x - 1);
    }
    else if (x == L[n - 1] + 2)
    {
        ans += (P[n - 1] + 1);
    }
    else if (L[n - 1] + 3 <= x && x <= L[n] - 1)
    {
        ans += (P[n - 1] + 1)+dfs(n - 1, x - (L[n - 1] + 2));
    }
    else if (x == L[n])
    {
        ans += P[n];
    }
    return ans;
}
int main()
{
    L[0] = 1, P[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        L[i] = L[i - 1] * 2 + 3;
        P[i] = P[i - 1] * 2 + 1;
    }
    ll N, X;
    cin >> N >> X;
    cout << dfs(N, X) << endl;
}
