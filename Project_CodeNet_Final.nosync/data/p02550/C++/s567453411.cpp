#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,bool>
#define mp make_pair

using namespace std;

ll n,x,m;

const int nax = 1e5 + 5;

ll a[nax];

ll fi[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x>>m;
    a[1] = x;
    for(int i=2;i<nax;i++)
    {
        a[i] = (a[i-1] * a[i-1]) % m;
    }

    ll st = -1;
    ll kn = -1;

    for(int i=1;i<nax;i++)
    {
        ll cur = a[i];
        if(fi[cur] > 0)
        {
            st = fi[cur];
            kn = i;
            break;
        }
        else fi[cur] = i;
    }

    ll ans = 0;

    if(n < nax)
    {
        for(int i=1;i<=n;i++)
        {
            ans += a[i];
        }
        cout<<ans;
        return 0;
    }

    ll cyc_len = kn - st;
    for(int i=1;i<st;i++)
    {
        ans += a[i];
    }
    ll cyc_sum = 0;
    for(int i=st;i<kn;i++)
    {
        cyc_sum += a[i];
    }
    ll rest = n - st + 1;
    ll cyc_cnt = rest / cyc_len;


    ans += cyc_cnt * cyc_sum;
    n -= cyc_cnt * cyc_len;

    for(int i=st;i<=n;i++)
    {
        ans += a[i];
    }
    cout<<ans;

    return 0;
}
