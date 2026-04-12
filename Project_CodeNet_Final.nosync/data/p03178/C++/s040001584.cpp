#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=10000+5;
const int K=100+5;
const int MOD=(int)1e9+7;

int add(int a,int b)
{
    a+=b;
    if(a>=MOD)
    {
        a-=MOD;
    }
    if(a<0)
    {
        a+=MOD;
    }
    return a;
}

int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

int dp[N][K];
int dp2[N][K];
int n;
string s;
int k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    n=s.size();
    s="0"+s;
    for(int i=1;i<=9;i++)
    {
        dp[1][i%k]++;
    }
    for(int i=0;i<=9;i++)
    {
        dp2[1][i%k]++;
    }
    dp2[0][0]=1;
    for(int l=2;l<=n;l++)
    {
        for(int ant=0;ant<k;ant++)
        {
            if(dp[l-1][ant]==0) continue;
            for(int put=0;put<=9;put++)
            {
                int now=(ant+put)%k;
                dp[l][now]=add(dp[l][now],dp[l-1][ant]);
            }
        }
    }
    for(int l=2;l<=n;l++)
    {
        for(int ant=0;ant<k;ant++)
        {
            if(dp2[l-1][ant]==0) continue;
            for(int put=0;put<=9;put++)
            {
                int now=(ant+put)%k;
                dp2[l][now]=add(dp2[l][now],dp2[l-1][ant]);
            }
        }
    }
    int ans=0;
    for(int l=1;l<n;l++)
    {
   //     cout<<l<<" : "<<dp[l][0]<<"\n";
        ans=add(ans,dp[l][0]);
    }
    int cur=0;
    for(int p=0;p<=n;p++)
    {
        cur=add(cur,s[p]-'0');
        if(p==n)
        {
            if(cur%k==0)
            {
                ans=add(ans,1);
            }
            continue;
        }
        int delta=ans;
        int st;
        if(p==0) st=1;
        else st=0;
        int dr=s[p+1]-'0'-1;
      ///  cout<<st<<" "<<dr<<"\n";
        for(int now=st;now<=dr;now++)
        {
            cur+=now;
            int inv=-cur;
            inv%=k; inv+=k; inv%=k;
            ans=add(ans,dp2[n-p-1][inv]);
      ///      cout<<p<<" ::: "<<cur<<" , "<<n-p<<" "<<inv<<"\t\t\t\t "<<dp2[n-p][inv]<<"\n";
            cur-=now;
        }
     ///   cout<<p<<" "<<ans-delta<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
