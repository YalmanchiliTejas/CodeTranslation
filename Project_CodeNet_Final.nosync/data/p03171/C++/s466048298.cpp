#include<bits/stdc++.h>

using namespace std;

using ll=long long;

vector<vector<ll>>dp(3010,vector<ll>(3010,0));

int main()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int lo=n-1;lo>=0;lo--)
    {
        for(int hi=lo;hi<=n-1;hi++)
        {
            if(lo==hi)
                dp[lo][hi]=a[lo];
            else
                dp[lo][hi]=max(a[lo]-dp[lo+1][hi],a[hi]-dp[lo][hi-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
