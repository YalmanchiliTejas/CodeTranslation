#include<bits/stdc++.h>
#define ll long long
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
#define mod 1000000007L
using namespace std;
char s[10005];
ll d,n;
ll memo[105][10005][2][2];
ll dp(ll sum,ll i,ll smaller,ll flag)
{
    //watch(sum)
    //watch(i)
    //watch(smaller)
    //watch(flag)
    ll cnt=0,max_digit;
    if(memo[sum][i][smaller][flag]!=-1)
    {
        return memo[sum][i][smaller][flag];
    }
    if(i==n)
    {
        if(sum==0&&flag)
        {
            return 1;
        }
        return 0;
    }
    if(smaller)
    {
        max_digit=9;
    }
    else
    {
        max_digit=s[i]-'0';
    }
    //watch(max_digit)
    for(ll j=0;j<=max_digit;++j)
    {
        ll temp_smaller=1,temp_flag=flag;
        if(!smaller&&j==max_digit)
        {
            temp_smaller=0;
        }
        if(j)
        {
            temp_flag=1;
        }
        //watch(i)
        //watch(j)
        //watch(temp_smaller)
        cnt=(cnt+dp((sum+j)%d,i+1,temp_smaller,temp_flag))%mod;
        //watch(cnt)
    }
    return memo[sum][i][smaller][flag]=cnt;
}
int main()
{
    scanf("%s%lld",s,&d);
    n=strlen(s);
    memset(memo,-1,sizeof memo);
    printf("%lld",dp(0,0,0,0));
    return 0;
}


