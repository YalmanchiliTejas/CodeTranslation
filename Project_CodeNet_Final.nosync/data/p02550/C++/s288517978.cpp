#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define f first
#define s second
#define matrix vector<vector<char>>
#define zero(n,m) matrix(n , vector<char>(m,'0'))
#define one(n,m) matrix(n , vector<ll>(m,1))
#define pii pair<int,int>
#define point complex<ld>
#define angle(a) (atan2((a).imag() , (a).real() ))
#define pi acos(-1)
#define X real()
#define Y imag()
const int N = 2e5+5;

ll n,x,m,xx;
ll vis[N],pre[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> x >> m;
    xx=x;

    ll sum = 0;
    for(int i=1; i<=min(n , (ll)200000); i++)
    {
        if (x==0)
        {
            return cout << sum << '\n' , 0;
        }
        sum += x;
        x = (x*x)%m;
    }

    x=xx;
    ll tmp=0 , len=0 , ans=0 , numOfCy;
    sum = 0;
    for(int i=1; i<=min(n,(ll)200000); i++)
    {
        if (vis[x])
        {
            pre[i] = (pre[i-1]+x);
            tmp = pre[i] - pre[vis[x]];
            len = i - vis[x]; //len of cycle

            //ans without cycles
            ans = pre[vis[x]-1]; //not cycle

            //ans of cycles
            n -= (vis[x]-1);
            numOfCy = n / len;
            ans += tmp*numOfCy;
            n -= len*numOfCy;

            for(int j=1; j<=n; j++)
            {
                ans += x;
                x = (x*x)%m;
            }
            return cout << ans << '\n' , 0;
        }

        sum += x;
        vis[x] = i;
        pre[i] = (pre[i-1]+x);

        x = (x*x)%m; //nxt x
    }

    cout << sum << '\n';

    return 0;
}