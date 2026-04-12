#include <bits/stdc++.h>
using namespace std;

string s;
int D;
long long dp[10010][110][2] , mod = 1e9 + 7;

long long get(int i = 0 , int sum = 0 , bool flag = 0)
{
    if(i == s.size())return (sum == 0);
    long long &ret = dp[i][sum][flag];
    if(~ret)    return ret;

    ret = 0;
    for(int j = 0 ; j <= (flag ? 9 : s[i] - '0') ; j++)
        ret = (ret + get(i+1,(sum + j)%D, flag | (j < s[i] - '0')))%mod;

    return ret;
}
int main()
{
    cin.tie();  ios::sync_with_stdio(false);
    cin >> s >> D;
    memset(dp,-1,sizeof dp);
    cout << (get() +mod - 1)%mod<< '\n';
    return 0;
}
