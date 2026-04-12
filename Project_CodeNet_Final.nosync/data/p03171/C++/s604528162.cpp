#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll maxcoin(vector<ll> &A) {
    int n = A.size();
    vector<vector<pair<ll, ll> > > dp(n, vector<pair<ll, ll> >(n));
    for(int i=0; i<n; i++)
    {
        dp[i][i].first = A[i];
        dp[i][i].second = 0;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j+i<n; j++)
        {
            pair<ll, ll> &r = dp[j][j+i];
            if(A[j]+dp[j+1][j+i].second > A[j+i]+dp[j][j+i-1].second)
            {
                r.first = A[j]+dp[j+1][j+i].second;
                r.second = dp[j+1][j+i].first;
            }
            else
            {
                r.first = A[j+i]+dp[j][j+i-1].second;
                r.second = dp[j][j+i-1].first;
            }
        }
    }
    return dp[0][n-1].first - dp[0][n-1].second;
}


int main()
{
	ll n;
	cin >> n;
	vector<ll> A(n);
	for(int i=0; i<n; i++) cin >> A[i];
	cout <<  maxcoin(A);
	
	
}