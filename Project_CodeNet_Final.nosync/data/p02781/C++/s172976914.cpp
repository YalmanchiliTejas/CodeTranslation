#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll zero=0;
    string n;   //xyz///
    ll k;
    cin>>n>>k;
    ll s=n.size();
    ll dp0[110][5],dp1[110][5];
    m0(dp0);
    m0(dp1);
    dp1[0][0]=1;
    for (int i = 0; i < s; i++)
    {
        int num=n[i]-'0';
        for (int j = 0; j <= k; j++)
        {
            dp0[i+1][j]+=dp0[i][j];
            dp0[i+1][j+1]+=dp0[i][j]*9;
            if(num>0)
            {
                dp0[i+1][j]+=dp1[i][j];

                dp0[i+1][j+1]+=dp1[i][j]*(num-1);
                dp1[i+1][j+1]+=dp1[i][j];
            }
            else //num=0
            {
                dp1[i+1][j]+=dp1[i][j];
            }
        }
    }
    
    cout<<dp0[s][k]+dp1[s][k]<<endl;

    return 0;
}