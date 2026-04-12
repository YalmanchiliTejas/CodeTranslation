#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> y;  int n; ll d;

const int MAXN = 10000;
const int MAXD = 105;
const ll MOD = 1000000007;

ll dp[MAXN + 1][MAXD + 1][2] = {-1};

ll count(int idx, ll sum_so_far,int lo)
{
    int n = y.size();
    if(idx==n)
        return (sum_so_far%d ==0)*1LL;
        
    if(dp[idx][sum_so_far%d][lo]!=-1)
       return dp[idx][sum_so_far%d][lo];

    ll result =0;   
    ll limit = lo==1?9:y[idx];
    for(ll x =0;x<=limit;x++)
    {         
        result=(result + count(idx+1,(sum_so_far+x)%d ,lo||x<y[idx]) )%MOD;
    }
    dp[idx][sum_so_far%d][lo] = result;
    return result; 
}
int main()
{
    string s;
    cin>>s>>d;

    for(int i =0 ;i<s.length(); i++)
        y.push_back(s[i] -'0');
    n = s.length();

    memset(dp , -1, sizeof(dp));
    ll ans = (count(0, 0, false) + (MOD - 1))%MOD;
    cout<<ans<<"\n";

}