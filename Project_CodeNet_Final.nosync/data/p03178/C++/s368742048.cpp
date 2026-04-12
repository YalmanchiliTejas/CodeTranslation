#include <iostream>
#include<map>
using namespace std;
string s;
int d,dp[100005][2][105];
int solve(int index, int less,int sum)
{
    if (index == s.size())
        return !(sum%d);
    if (dp[index][less][sum] != -1)
        return dp[index][less][sum];
    int ans = 0;
    for (int i = 0; i <=9 ; i++)
    {
        if(less||s[index]-'0'>i)
        ans=(ans% 1000000007 +solve(index+1 , 1 ,(sum+i)%d)% 1000000007)% 1000000007;
        else if(s[index]-'0'==i)
        {
           ans=(ans%1000000007+solve(index + 1, 0 ,(sum+i)%d)% 1000000007)% 1000000007;
        }
    }
    return dp[index][less][sum]=ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < 100005; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 105; k++)
                dp[i][j][k] = -1;
    cin >> s >>d;
    cout << (solve(0,0,0)-1+1000000007)%1000000007;
    return 0;
}
