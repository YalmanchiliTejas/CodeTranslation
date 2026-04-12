#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=3003;
long long int dp[nax][nax];

int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i][i]=a[i];
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            if(j>n) continue;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
