//    .------------------------------------------------------------.
//    |     ___   ___   _____     _     ___   ___    ___   ___     |
//    |    | _ \ | __| |_   _|   /_\   | _ \ |   \  | __| |   \    |
//    |    |   / | _|    | |    / _ \  |   / | |) | | _|  | |) |   |
//    |    |_|_\ |___|   |_|   /_/ \_\ |_|_\ |___/  |___| |___/    |
//    |                                                            |
//    |              ___    ___    ___    ___   ___                |
//    |             / __|  / _ \  |   \  | __| | _ \               |
//    |            | (__  | (_) | | |) | | _|  |   /               |
//    |             \___|  \___/  |___/  |___| |_|_\               |
//    |                                                            |
//    |------------------------------------------------------------|
//    |                      .------------.                        |
//    |                      | KerakTelor |                        |
//    |                      |------------|                        |
//    |                      | 2019-11-07 |                        |
//    |                      '------------'                        |
//    '------------------------------------------------------------'

#include <bits/stdc++.h>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("tune=native")

#define fi first
#define se second

using namespace std;

using ll=long long;
using ld=long double;

template<class T>
using vec=vector<T>;
template<class T>
using v2d=vector<vector<T>>;
template<class T>
using prq=priority_queue<T>;
template<class T>
using rpq=priority_queue<T,vector<T>,greater<T>>;

vec<ll> arr;
v2d<ll> dp;

ll solve(int l,int r,bool f)
{
    if(l>r)
        return 0;
    if(dp[l][r])
        return dp[l][r];
    ll res;
    if(f)
        res=max(solve(l+1,r,f^1)+arr[l],solve(l,r-1,f^1)+arr[r]);
    else
        res=min(solve(l+1,r,f^1)-arr[l],solve(l,r-1,f^1)-arr[r]);
    return dp[l][r]=res;
}

int main()
{
    int n;
    scanf("%d",&n);
    arr.assign(n,0);
    dp.assign(n,vec<ll>(n,0));
    for(auto &i:arr)
        scanf("%lld",&i);
    printf("%lld\n",solve(0,n-1,1));
}

