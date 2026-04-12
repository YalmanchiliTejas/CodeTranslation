#include<bits/stdc++.h>
#define mod   1000000007
using namespace std;
const int N = 1e4 + 5;
const int M = 105;
vector<long long>num;
int dp[N][M][2];
int n, m;
string s;
int d;
long long help(long long idx, long long sum, long long tight)
{
    if (idx == num.size())
        return (sum%d==0);
    if (dp[idx][sum][tight] != -1)
        return dp[idx][sum][tight];
    long long res = 0;
    int biggest;
    if (tight)
     biggest= (num[idx]) ;
     else
        biggest=9;
    for (int i = 0; i <= biggest; i++)
    {
        int newtight = ((num[idx])== i) ? tight : 0;
        res =(res+help(idx + 1, (sum + i) % d, newtight))%mod;
    }
    return dp[idx][sum][tight] = res;
}
long long solve(string s)
{
    memset(dp, -1, sizeof dp);
    num.clear();
    for(int i=0;i<=s.size()-1;i++)
        num.push_back(s[i]-'0');
    return (help(0, 0, 1) -1 + mod) % mod;
}
int main()
{
    cin>>s;
    cin>>d;
    cout<<solve(s);
    return 0;
}
