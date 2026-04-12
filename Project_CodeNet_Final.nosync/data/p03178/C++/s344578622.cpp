#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>
#define pb push_back
#define ll long long
using namespace std;
int d;
int n;//lungimea lui k
string k;
const int mod = 1e9+7;
ll a[410];
ll dp[10010][110][3];
int main()
{
    ll num;
    ifstream fin("z.in");
    ofstream fout("z.out");
    cin>>k;
    cin>>d;
    n=k.length();
    dp[0][0][1]=1;
    int zero='0';
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int p=0;p<=d-1;p++)
            {
                num=(((p-j)%d)+d)%d;
                dp[i+1][num][0]+=dp[i][p][0];
                if(j<k[i]-'0')
                {
                    dp[i+1][num][0]+=dp[i][p][1];
                }
                else if(j==k[i]-'0')
                {
                    dp[i+1][num][1]+=dp[i][p][1];
                }
                dp[i+1][num][0]%=mod;
                dp[i+1][num][1]%=mod;
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][0][1]+mod-1)%mod<<endl;
    fin.close();
    fout.close();
    return 0;
}
