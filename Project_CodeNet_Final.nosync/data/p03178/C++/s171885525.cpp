#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#define int int64_t
#define endl "\n"
#define mod 1000000007
using namespace std;

void io()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

string s;
int d;

int dp[10002][102][2];

int solve(int pos,int sum,int tight){
    if(pos == s.length()+1){
        if(sum % d == 0){
            return 1;
        }else return 0;
    }

    if(dp[pos][sum][tight]!=-1){
        return dp[pos][sum][tight];
    }

    int end = ((tight ? (s[pos-1]-'0') : 9));
    int ans=0;
    for (int i = 0; i <= end; i++)
    {
        ans = ans + solve(pos+1,(sum+i%d)%d,tight&(i == end))%mod;
    }
    return dp[pos][sum][tight]=ans;
    
}

void Solution()
{
    cin >> s >> d;
    memset(dp,-1,sizeof dp);
    cout << (solve(1,0,1)-1)%mod;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //io();
    Solution();
}