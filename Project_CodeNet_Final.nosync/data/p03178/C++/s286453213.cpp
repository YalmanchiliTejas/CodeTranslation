#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll inf=1000000007;
const ll maxinput=10005;
const ll mod=998244353;
#define mp make_pair
int a[maxinput];int d;
int dp[maxinput][105][2];
int countnumdivbyd(int pos,int rem,int issmall)
{
    if(pos==maxinput)
    {
        if(rem%d==0)
            return(1);
        else
            return(0);
    }
    if(dp[pos][rem][issmall]!=-1)
        return(dp[pos][rem][issmall]);
    int temp=0;
    if(issmall)
    {
        for(int i=0;i<=9;i++)
            temp+=countnumdivbyd(pos+1,(rem+i)%d,issmall)%inf,temp%=inf;

    }
    else
    {
        for(int i=0;i<a[pos];i++)
            temp+=countnumdivbyd(pos+1,(rem+i)%d,1)%inf,temp%=inf;

        temp+=countnumdivbyd(pos+1,(rem+a[pos])%d,0)%inf,temp%=inf;
    }

    return(dp[pos][rem][issmall]=temp%inf);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<maxinput;i++)
        a[i]=0;

    string k;cin>>k;
    int l1=k.length();
    for(int i=0;i<l1;i++)
        a[maxinput-l1+i]=k[i]-'0';

    cin>>d;
    
    cout<<((countnumdivbyd(0,0,0)-1)+inf)%inf<<"\n";    

}