#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll Inf = 1e18;

ll Rec(ll l,ll r,bool Turn);

ll n;
ll a[3030];
ll Sum;

ll Dp[3030][3030][2];

int main()
{
    for(ll l=0;l<3030;l++)
        for(ll r=0;r<3030;r++)
            Dp[l][r][0] = Dp[l][r][1] = -Inf;

    cin>>n;

    for(ll i=0;i<n;i++) scanf("%I64d",a+i) , Sum += a[i];

    cout<<Rec(0,n-1,true);
}

ll Rec(ll l,ll r,bool Turn)
{
    if(l>r) return 0;

    if(Dp[l][r][Turn]+Inf)  return Dp[l][r][Turn];

    if(Turn)    return Dp[l][r][Turn] = max( a[l] + Rec(l+1,r,!Turn) , a[r] + Rec(l,r-1,!Turn) );
    else        return Dp[l][r][Turn] = min(-a[l] + Rec(l+1,r,!Turn) ,-a[r] + Rec(l,r-1,!Turn) );

}
