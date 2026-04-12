#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define PI acos(-1)
#define pb push_back
#define int long long
#define ld long double
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int M = (1e9)+7;
const int N = 1e6+5;

int mpower(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1){
            res = (res*x) % p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        int n;
        cin>>n;
        int s = 0;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i],s+=a[i],s%=M;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int add = (a[i]*(s-a[i]+M)%M)%M;
            ans += add;
            ans %= M;
        }
        ans *=  mpower(2LL,M-2,M);
        ans %= M;
        cout<<ans<<endl;
    }
    return 0;
}
