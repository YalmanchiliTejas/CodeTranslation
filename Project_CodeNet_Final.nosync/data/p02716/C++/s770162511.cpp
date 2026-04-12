#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}

const int MAX = 2e5 + 5;

int n;

int a[MAX];

ll dp[MAX][3]; // dp[N][K] holds the maximum sum of choosing N / 2 element and skipping at most K elements

ll solve(int idx, int k)
{
    if (idx > n)
    {
        return k ? -1e17 : 0;
    }
    
    ll &ret = dp[idx][k];

    if (~ret)
    {
        return ret;
    }
    ret = -1e17;

    if (k) // you can skip k elements in the serius
    {
        ret = max(ret, solve(idx + 1, k - 1));
    }
    ret = max(ret, solve(idx + 2, k) + a[idx]);
    return ret;

}

int main(int argc, char const *argv[])
{
    file();
    
    cin>>n;

    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    cout<<solve(0, (n & 1) + 1);
        

}