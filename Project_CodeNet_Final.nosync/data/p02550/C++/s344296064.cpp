#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define PI acos(-1)
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define sp fixed<<setprecision
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int M = 998244353;
const int N = 1e6+5;

int a[N];
int first[N];

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        int n,x,m;
        cin>>n>>x>>m;
        if(!x)return cout<<0,0;
        int id = 1;
        first[x] = 1;
        a[id++] = x;
        while(id <= n)
        {
            x = x*x;
            x %= m;
            if(first[x])break;
            first[x] = id;
            a[id++] = x;
        }
        int ans = 0;
        if(id > n)for(int i=1;i<=n;i++)ans += a[i];
        else
        {
            int lim = first[x];
            for(int i=1;i<lim;i++,n--)ans += a[i];
            int sum = 0,len = id - lim;
            for(int i=lim,j=0;j<len;j++,i++)sum += a[i];
            ans += (sum*(n/len));
            n %= len;
            for(int i=lim,j=0;j<n;j++,i++)ans += a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
