#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;
typedef vector<li> vi;
typedef pair<li,li> pi;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define f(i,l,r) for(li i=l;i<=r;++i)
#define fr(i,l,r) for(li i=l;i>=r;--i)
#define u_map unordered_map
#define endl "\n"
#define debug(x) cout<<#x<<" = "<<x<<endl;

li fastpow(li base,li exp,li M) 
{
    li res=1;
    while(exp>0) {
        if(exp&1)
            res=(res*base)%M;

        base=(base*base)%M;
        exp>>=1;
    }
    return res;
}

const int N=3005;
li dp[N][N];

void solve()
{
    li n;

    cin>>n;

    vi a(n);

    f(i,0,n-1)
    {
        cin>>a[i];
    }

    fr(l,n-1,0)
    {
        f(r,l,n-1)
        {
            if(l==r)
            {
                dp[l][r]=a[l];
            }
            else
            {
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }

    cout<<dp[0][n-1];
}

int main()
{    
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li t=1;

    // cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}