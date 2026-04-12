#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll tot[51],sz[51],x;
ll recur(int n)
{
    if(x<=0)
        return 0;
    if(sz[n]<=x)
    {
        x-=sz[n];
        return tot[n];
    }
    x--;
    ll y=recur(n-1);
    if(x)
        y++,x--;
    if(x)
        y+=recur(n-1);
    return y;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    tot[0]=1;
    sz[0]=1;
    for(int i=1; i<=50; i++)
        tot[i]=tot[i-1]*2ll + 1;
    for(int i=1; i<=50; i++)
    {
        sz[i]=sz[i-1]*2ll + 3;
    }
    ll n,ans=0;
    cin>>n>>x;
    x--;
    if(x)
    {
        ans+=recur(n-1);
    }
    if(x)
    {
        x--;
        ans++;
    }
    if(x)
    {
        ans+=recur(n-1);
    }
    cout<<ans<<endl;





    return 0;
}
