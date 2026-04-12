#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pII;
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof(x))
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=1e6+5;
//ll fmod(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
//ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll a[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0; i < n; ++i)cin>>a[i];
        sort(a,a+n);
        ll ans = 0;
        int x = 0,y = n - 1;
        ll xx = a[x],yy = a[y];
        ans += abs(xx - yy);
        x++;y--;
        int now = 1;
        int cnt = 0;
        while(y >= x)
        {
            cnt++;
            //cout<<ans<<endl;
            if(x == y)
            {
                ans += max(abs(a[x] - xx),abs(a[x] - yy));
                break;
            }

            if(cnt <= 2)
            {
                if(now&1)
            {
                ans += abs(a[y] - xx);
                xx = a[y];
                y--;
            }
            else
            {
                ans += abs(a[x] - yy);
                yy = a[x];
                x++;
            }

            }
            else
            {
                if(now&1)
            {
                ans += abs(a[y] - yy);
                yy = a[y];
                y--;
            }
            else
            {
                ans += abs(a[x] - xx);
                xx = a[x];
                x++;
            }

            }

            if(cnt == 4)
            cnt = 0;

            //cout<<ans<<"  "<<xx<<"  "<<yy<<endl;
            now ^= 1;
        }
        printf("%lld\n",ans);
    }
}











