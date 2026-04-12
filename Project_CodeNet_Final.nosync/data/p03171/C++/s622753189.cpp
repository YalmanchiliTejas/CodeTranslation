#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 3000
#define ll long long
ll fun(ll a[],ll dp[][MAX], int l,int r)
{
    if(dp[l][r]!=-1) return dp[l][r]; // means already calculated
    if(r==l+1) return max(a[l],a[r]);
    if(r==l) return a[l];
    if(l>r) return 0;
    ll option1 = a[l] + min(fun(a,dp, l+2,r), fun(a,dp,l+1,r-1));
    ll option2 = a[r] + min(fun(a,dp, l+1,r-1), fun(a,dp,l,r-2));
    dp[l][r] = max(option1, option2);
    return dp[l][r];
}
int main()
{
        int n;
        cin >> n;
        ll a[n];
      	ll dp[n][MAX];
        memset(dp, -1, sizeof(dp)); //set every element to -1
        int i;
      	ll sum = 0;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        cout << 2*fun(a,dp,0,n-1)-sum << endl;

}
