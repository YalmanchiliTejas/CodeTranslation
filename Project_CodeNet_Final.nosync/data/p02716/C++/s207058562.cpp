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

int main()
{    
   

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li n;

    cin>>n;

    li a[n+1];

    f(i,1,n)
    {
        cin>>a[i];
    }

    vi sum(n+1);

    vi dp(n+1);

    f(i,1,n)
    {
        sum[i]=(i>2?sum[i-2]:0)+a[i];
    }

    f(i,2,n)
    {
        if(i&1)
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else
            dp[i]=max(sum[i-1],dp[i-2]+a[i]);
    }

    cout<<dp[n];

    return 0;
}