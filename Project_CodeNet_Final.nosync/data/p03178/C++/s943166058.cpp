#include <bits/stdc++.h>
using namespace std;
#define oo 666666666
#define ll long long
#define ld long double

ll mod = 1e9+7;
ll D;
ll DP[100001][2][101];

ll dp(int pos, vector<int>&digits, int pf, ll sum)
{
    if(pos >= digits.size())return sum==0;
    if(DP[pos][pf][sum]!=-1)return DP[pos][pf][sum];
    ll ats = 0;

    for(int j=0; j<=(pf ? digits[pos] : 9); j++)
        {
            ats+=dp(pos+1,digits,pf&(j==digits[pos]),(sum+j)%D);
            ats%=mod;
        }

    return DP[pos][pf][sum]=ats;
}

ll solve(string s)
{
    vector<int>digits;
    for(auto&ch:s)digits.push_back(ch-'0');
    memset(DP, -1, sizeof DP);
    return dp(0,digits,1,0);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string K;
    cin>>K>>D;
    cout<<(solve(K)-1+mod)%mod;
}
