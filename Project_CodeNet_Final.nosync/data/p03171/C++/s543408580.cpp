#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

vector<vector<ll>> range_sum(vector<ll>& v)
{
    int n = v.size();

    vector<vector<ll>> dp(n,vector<ll>(n));

    for (int i=0;i<n;++i) dp[i][i] = v[i];

    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            dp[i][j] = dp[i][j-1] + v[j];
        }
    }
    /**
    for (auto b:dp)
    {
        for (auto x:b)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    **/
    return dp;
}

ll solve(vector<ll>& v)
{
    int n = v.size();

    vector<vector<ll>> rs = range_sum(v);

    vector<vector<ll>> dp(n,vector<ll>(n));
    /**
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            dp[i][j] = rs[i][j];
            ll a = (i<j)?dp[i+1][j]:0;
            ll b = (j>i)?dp[i][j-1]:0;

            dp[i][j] -= min(a,b);
        }
    }
    **/

    for (int s=1;s<=n;++s)
    {
        int lim = n - s;
        for (int i=0;i<=lim;++i)
        {
            int j = i + s - 1;
            dp[i][j] = rs[i][j];
            ll a = (i<j)?dp[i+1][j]:0;
            ll b = (j>i)?dp[i][j-1]:0;

            dp[i][j] -= min(a,b);
        }
    }
    /**
    cout<<"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<endl;
    for (auto b:dp)
    {
        for (auto x:b)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    **/
    ll my = dp[0][n-1];
    //cout<<"M"<<my<<endl;
    ll his = rs[0][n-1] - dp[0][n-1];
    //cout<<"H"<<his<<endl;
    return my-his;
}

int main()
{
    int N;
    cin>>N;
    vector<ll> v(N);

    for (int i=0;i<N;++i)
    {
        cin>>v[i];
    }

    cout<<solve(v)<<endl;

    return 0;
}
