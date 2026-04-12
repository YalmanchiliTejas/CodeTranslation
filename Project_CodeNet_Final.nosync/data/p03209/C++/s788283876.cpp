#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<ll> p(52), b(52), s(52);

ll find(ll n, ll x)
{
    if(n*x==0){
        if(x>=1)
            return 1;
        else
            return 0;
    }

    if (0 < x && x < s[n - 1] + 2)
    {
        return find(n - 1, x - 1);
    }
    else
    {
        return p[n - 1] + 1+find(n - 1, x - 2 - s[n - 1]);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    p[0] = 1;
    s[0] = 1;
    b[0] = 0;
    rep(i, 50)
    {
        b[i + 1] = 2 + 2 * b[i];
        p[i + 1] = 1 + 2 * p[i];
        s[i + 1] = b[i + 1] + p[i + 1];
    }

    cout << find(n, x) << endl;

    return 0;
}
