#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
ll dp(ll n, ll x)
{
    ll res = 0;
    if (n == 0 && x == 1)
    {
        
        return 1;
    }
    else if (x == 1)
    {
        return 0;
    }
    else if (1 < x && x <= pow(2, n + 1) - 3 + 1)
    {
        //  cout << x << " " << n << pow(2, n + 1) - 3 + 1 << endl;
        res = dp(n - 1, x - 1);
    }
    else if (x == pow(2, n + 1) - 3 + 2)
    {
        //cout << "f3";
        res = pow(2, n); //2^(n+1)-1+1;
    }
    else if (pow(2, n + 1) - 3 + 2 < x && x < pow(2, n + 2) - 3)
    {
        // cout << "f4";
        res = pow(2, n) + dp(n - 1, x - pow(2, n + 1) + 3 - 2); //今までにどんぐらい食べたのか
    }
    else
    {
        // cout << "f5";
        res = pow(2, n + 1) - 1;
    }
    return res;
}
int main()
{
    ll n;
    ll x;
    cin >> n >> x;
    cout << dp(n, x);
    //まずレベルnバーガーがどのようなものなのかを理解しておかなければならない・
    //50だと10^15で大きさ的にはダメ。50でなんとかしたいところ。
    //pは2^(n+1)-1
    //大きさは2^(n+2)-3
    //x食べた時には、どの層に当たるのでしょうか。(1の時はB,2~an-1+1の時は下からx-1個食べた時と等しい、　a(n-1)+2はp,a(n-1)+3~2*a(n-1)+2だと、下から、x-)
}