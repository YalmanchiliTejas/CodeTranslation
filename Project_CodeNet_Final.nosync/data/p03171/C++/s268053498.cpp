#include<iostream>
#define ll long long
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_set>
#include <iomanip>
using namespace std;
ll ans = 0;



int main()
{
    ll n;
    cin>>n;
    ll dp[n][n];
    ll elements[n];
    for(ll i=0; i< n; ++i){
        cin>>elements[i];
    }
    for(int  i=n-1; i>=0; --i)
    {
        for(int j=i; j<n; ++j)
        {
            if(i==j)
            {
                dp[i][j] = elements[i];
            }
            else
            {
                dp[i][j] = max( (elements[i] - dp[i+1][j]) ,(elements[j] - dp[i][j-1]) );
            }

        }
    }

    cout<<dp[0][n-1];
    return 0;
}
