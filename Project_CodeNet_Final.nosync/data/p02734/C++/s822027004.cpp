/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
ll dp[3030];
ll arr[3030];
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    ll chaeng = 0;
    for(i=1;i<=n;i++)
    {
        dp[0] += 1;
        for(j=k;j>=0;j--)
        {
            if(j + arr[i] <= k) dp[j+arr[i]] = (dp[j+arr[i]] + dp[j]) % mod;
        }
        chaeng += dp[k];
        chaeng %= mod;
    }
    cout << chaeng << endl;
    return 0;
}
