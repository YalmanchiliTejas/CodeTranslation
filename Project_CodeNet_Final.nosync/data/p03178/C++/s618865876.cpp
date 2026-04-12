#include <bits/stdc++.h>

using namespace std;
const int N=1e4+55;
int dp[N][155][2];
int m=1e9+7;
string k;
int d;
int n;

int bt(int i , int s , bool q)
{
    if(i==-1)
        return (s==0);
    if(dp[i][s][q]!=-1)
        return dp[i][s][q];
    int ret=0;
    for(int j=0;j<=9;j++)
    {
        if(q&&(j==(k[i]-'0')))
        {
            ret+=bt(i-1,(s+j)%d,1);
            break ;
        }
        ret+=bt(i-1,(s+j)%d,0);
        ret%=m;
    }
    ret%=m;
    dp[i][s][q]=ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof dp);
    ios::sync_with_stdio(false);
    cin>>k;
    n=k.size();
    reverse(k.begin(),k.end());
    cin>>d;
    cout<<(m+bt(n-1,0,1)-1)%m<<endl;
    return 0;
}
