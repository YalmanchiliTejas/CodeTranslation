/**
    Find the number of integers between [1, n]
    satisfying the following condition:
    The sum of the digits is a multiple of D
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long 

vector<int> num;
ll DP[10004][103][2],d;

ll call(int pos, int sum, int flag)
{
    if(pos == (int)num.size())
        return sum%d==0;
    if(~DP[pos][sum][flag]) 
        return DP[pos][sum][flag];
    
    ll ans = 0;
    for(int i = 0; i<10; i++)
    {
        if(flag && i==num[pos]) 
        {
            ans = (ans + call(pos+1, (sum+i)%d, 1))%MOD;
            break;
        }
        ans = (ans + call(pos+1, (sum+i)%d, 0))%MOD;
    }
 
    return DP[pos][sum][flag]=ans;
}

ll solve(string& s)
{
    num.clear();
    for(int i=0; i<s.size(); i++)
        num.push_back(s[i]-'0');
    memset(DP, -1, sizeof(DP));
    return (call(0, 0, 1)-1+MOD)%MOD;
}

int main ()
{
    string n;
    cin>>n>>d;
    cout<<solve(n)<<endl;
    return 0;
}
