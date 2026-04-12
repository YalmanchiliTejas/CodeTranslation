// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroint-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define pi 3.14159265359
#define mp make_pair
#define ff first
#define ss second
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%intd",&a)
#define pf printf
#define sz(a) (int)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double
#define inf 1e18
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define eb emplace_back
#define vvlli vector<vector<ll> >
#define vlli vector<ll>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vstr vector<string>
#define vvstr vector<vector<string> >
ll binpow(ll a, ll b){ll res=1;while(b!=0){if(b&1)res*=a;a*=a;b>>=1;}return res;}

using namespace std;

ll d,dp[10001][2][2][100];
string l,r;

inline ll fn(int level, int tlo, int thi, int rem)
{
    if(level>=sz(l))
    {
        if(rem==0)
            return 1;
        return 0;
    }
    if(dp[level][tlo][thi][rem]==-1)
    {
        ll ans=0;
        int blo = 0,bhi = 9;
        if(tlo)
            blo = l[level]-'0';
        if(thi)
            bhi = r[level]-'0';
        f(i,blo,bhi+1)
        {
            int ntlo = tlo, nthi = thi;
            if(i > (l[level]-'0'))
                ntlo = 0;
            if(i < r[level]-'0')
                nthi = 0;
            ans += fn(level+1,ntlo,nthi,(rem+i)%d);
            ans%=mod;
        }
        dp[level][tlo][thi][rem] = ans;
    }
    return dp[level][tlo][thi][rem];
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>r>>d;
    l="1";
    while(sz(l)<sz(r))
        l+='0';
    reverse(all(l));
    cout<<fn(0,1,1,0)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
}