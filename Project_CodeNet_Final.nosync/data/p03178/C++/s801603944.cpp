#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 1000000007
#define ll long long

string k;
int d, n;
ll dp[N][105][2];

ll cal(int i, int rm, int is)
{
    if(i == n) return rm? 0 : 1;
    if(dp[i][rm][is] != -1) return dp[i][rm][is];
    int mx = is? (k[i] - '0') : 9;
    dp[i][rm][is] = 0;
    for(int j = 0; j <= mx; j++)
    {
        dp[i][rm][is] = (dp[i][rm][is] + cal(i + 1, (rm + j) % d, (is && j == mx) ? true : false)) % M;
    }
    return dp[i][rm][is];
}


int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> k >> d;
    n = k.size();
    cout << (cal(0, 0, 1) - 1 + M) % M << endl;
}

