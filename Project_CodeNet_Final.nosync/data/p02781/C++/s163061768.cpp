#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define N 500050
using namespace std;
char a[10010];
int n,k,ans,f[1050][5];//表示第i位有J个非零数位的方案数
int main()
{
    cin>>a+1;
    cin>>n;
    int len=strlen(a+1);
    for(int i=1; i<=len; i++)
        a[i]-='0';
    f[0][0]=1;
    for(int i=1; i<=len; i++)
    {
        f[i][0]=f[i-1][0];
        for(int j=1; j<=3; j++)
        {
            f[i][j]=f[i-1][j]+9*f[i-1][j-1];//预处理
        }
    }
    int cnt=0;
    for(int i=1; i<=len; i++)
    {

        if(a[i])
        {
            if(n-cnt>=0)
                ans+=f[len-i][n-cnt];//接下来还有（len-i）位数，n-cnt的非零位
        }

        if(a[i]>1)
        {
            if(n-cnt-1>=0)
                ans+=(a[i]-1)*f[len-i][n-cnt-1];//本位可以取非零位
        }
        if(a[i])
            ++cnt;
    }
    if(cnt==n)
        ++ans;
    cout<<ans;
    return 0;
}
