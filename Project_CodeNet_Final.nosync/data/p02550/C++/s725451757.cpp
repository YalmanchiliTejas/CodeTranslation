#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxi = 1e6 + 1, mod = 998244353;
int fac[maxi];
ll modex(ll a, ll b, ll m)
{
    ll ans = 1;
    for(; b > 0; b >>= 1, a = (a * a) % m)
        if(b & 1)
            ans = (ans * a) % m;
    return ans;
}
int main()
{
    ll n, x, m, i;
    cin >> n >> x >> m;
    if(x == 0)
        cout << 0 << endl;
    else if(x == 1)
        cout << n << endl;
    else
    {
        ll p = 0, ele = -1;
        vector <int> a;
        set <int> s;
        while(1)
        {
            if(s.find(x) != s.end())
            {
                ele = x;
                p = s.size();
                break;
            }
            else
            {
                a.push_back(x);
                s.insert(x);
                x = (x * x) % m;
            }
        }
        for(i = 0; i < a.size(); i++)
        {
            if(a[i] == ele)
            {
                ele = i;
                break;
            }
        }
        ll ans = 0;
        if(a.size() >= n)
        {
            for(i = 0; i < n; i++)
                ans += a[i];
        }
        else
        {
            for(i = 0; i < ele; i++)
                ans += a[i];
            n -= max(0ll, ele);
            if(ele != -1)
            {
                p = a.size() - ele;
                for(i = ele; i < a.size(); i++)
                    ans += n / p * a[i];
                for(i = ele; i - ele < n % p; i++)
                    ans += a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}