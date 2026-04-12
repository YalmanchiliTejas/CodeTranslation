#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define HelloFile freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ll long long
#define F first
#define S second
#define lcm(a,b) ((a*b)/__gcd(a,b))
int d, dp[10005][2][102];
string k;
int add(int a, int b, int Mod)
{
    return (a + b) % Mod;
}
int solve(int idx, bool smaller, int sum)
{
    if(idx == k.size())
        return sum == 0;
    int &ans = dp[idx][smaller][sum];
    if(ans != -1)
        return ans;
    ans = 0;
    for(int digit = 0; digit <= 9; digit++)
    {
        if(!smaller && digit > k[idx] - '0')
            continue;
        bool newSmaller;
        if(smaller)
            newSmaller = 1;
        else
            if(digit < k[idx] - '0')
                newSmaller = 1;
            else
                newSmaller = 0;
        ans = add(ans, solve(idx + 1, newSmaller, add(sum, digit, d)), mod);
    }
    return ans;
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> k >> d;
    cout << (solve(0, 0, 0) - 1+mod ) % mod;
    return 0;
}
