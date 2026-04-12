#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<set>
#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)
#define INF9                1000000010
#define INF18               1000000000000000010
#define dist(ax,ay,bx,by)   sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define m_p(a,b)            make_pair(a,b)
#define sqr(a)              ((a)*(a))
#define pb                  push_back
#define bpll(a)             __builtin_popcountll(a)
#define MX                  100006
#define PI                  acos(-1)
#define mod                  1000000007
#define cnt_bin(n)          __builtin_clzll(0ll) - __builtin_clzll(n)

typedef long long lli;
using namespace std;

vector<lli>ara;

int main()
{
    lli n;
    scanf("%lld", &n);

    lli sum=0;

    for(lli i=0; i<n; i++)
    {
        lli a;
        scanf("%lld", &a);
        ara.push_back(a);
        sum+=a;
        sum%=mod;
    }

    lli ans=0;

    for(lli i=0; i<ara.size(); i++)
    {
        sum-=ara[i];
        sum= (sum+mod)%mod;

        ans+= (sum*ara[i]);
        ans%=mod;
    }

    cout<<ans<<endl;
    return 0;
}
