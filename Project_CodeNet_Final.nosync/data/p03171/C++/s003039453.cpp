#include <bits/stdc++.h>
     
using namespace std;

long long int dp[3001];
long long int psum[3001];
int n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        sum += t;
        psum[i+1] = psum[i] + t;
    }

    for(int l=1;l<=n;l++)
    {
        for(int i=0;i+l<=n;i++)
        {
            dp[i] = psum[i+l] - psum[i] - min(dp[i],dp[i+1]);
        }
    }

    long long int Y = sum - dp[0];
    long long int X = dp[0];
    cout << X - Y << '\n';

    return 0;
}