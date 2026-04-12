#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, x;
vector<ll> a(51);
vector<ll> p(51);
ll f(ll c, ll d)
{
    if(d == 1)
    {
      if(c == 0) return 1;
      else return 0;
    }
    else if(1 < d && d <= a[c-1]+1)
    {
        return f(c-1, d-1);
    }
    else if(d == a[c-1] + 2)
    {
        return p[c-1]+1;
    }
    else if(a[c-1]+2 < d && d <= 2 * a[c-1] + 2)
    {
        return p[c-1] + 1 + f(c-1, d-2-a[c-1]);
    }
    else if(d == 2 * a[c-1] + 3)
    {
        return 2 * p[c-1] + 1;
    }
    return 0;
}
int main()
{
    cin >> n >> x;
    
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << f(n, x) << endl;
}


