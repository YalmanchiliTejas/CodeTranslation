/* ***************************************
Author        :Scau.ion
Created Time  :2016/11/28 14:21:52 UTC+8
File Name     :ion.cpp
*************************************** */

#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<PII>
#define X first
#define Y second
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define IN freopen("in", "r", stdin);
#define OUT freopen("out", "w", stdout);

using namespace std;

LL dp[10000][8];

int main()
{
    dp[0][0]=1;
    for (int j=1;j<=600;++j)
    {
        dp[j][0]=1;
        for (int k=1;k<8;++k)
            dp[j][k]=dp[j-1][k]+dp[j-1][k-1];
    }
    LL n;
    cin>>n;
    string s="";
    for (int j=600;j>=1;--j)
    {
        int cs=0;
        if (dp[j][7]>0)
        {
            cs=n/dp[j][7];
            n%=dp[j][7];
        }
        for (int k=1;k<=cs;++k)
            s="L"+s;
        s="AVITSEF"+s;
    }
    cout<<s<<endl;
    return 0;
}
