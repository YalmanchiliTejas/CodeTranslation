#include <bits/stdc++.h>
#define ll long long
#define fort(i,n) for (int i = 1; i <= n; ++i)
#define pi pair<int,int>
#define pb push_back
#define sz size()
#define er erase
#define fr first
#define sc second
#define rc(x) return cout << x, 0
using namespace std;

ll n,x;

ll lay(ll n)
{
    if (n==0) return 1;
    else return lay(n-1)*2+3;
}

ll pat(ll n)
{
    if (n==0) return 1;
    else return pat(n-1)*2+1;
}

ll eat(ll n, ll x)
{
    if (x==1)
    {
        if (n) return 0;
        else return 1;
    }
    else if (x<=lay(n-1)+1) return eat(n-1,x-1);
    else if (x==lay(n-1)+2) return pat(n-1)+1;
    else if (x<=2+lay(n-1)*2) return pat(n-1)+1+eat(n-1,x-lay(n-1)-2);
    else return pat(n);
}

int32_t main()
{
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> x;
    cout << eat(n,x);
}
