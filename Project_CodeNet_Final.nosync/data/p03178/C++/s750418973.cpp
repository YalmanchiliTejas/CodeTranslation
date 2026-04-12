#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long 
vector<int> num;
ll DP[10004][103][2][2],d;

ll call(int pos, int sum, int small, int startHere)
{
    if(pos==(int)num.size())
    {
        return sum%d==0;
    }

    if(~DP[pos][sum][small][startHere]) return DP[pos][sum][small][startHere];

    ll res = 0;
    int LMT = small? 9 : num[pos];

    if(startHere)
    {
        res+=call(pos+1, 0, 1, 1);
    }
    for(int dgt=startHere; dgt<=LMT; dgt++)
    {
        res=(res+call(pos+1, (sum+dgt)%d, small|(dgt<num[pos]), 0)%MOD)%MOD;
    }

    return DP[pos][sum][small][startHere] = res;
}
ll solve(string& s)
{
    for(int i=0; i<s.size(); i++)
        num.push_back(s[i]-'0');
    memset(DP, -1, sizeof(DP));
    return (call(0, 0, 0, 1)-1+MOD)%MOD;
}

int main ()
{
    string s;
    cin>>s>>d;
    cout<<solve(s)<<endl;
    return 0;
}
