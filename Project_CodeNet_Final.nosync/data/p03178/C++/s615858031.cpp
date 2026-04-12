#include<iostream>
#include<string.h>
using namespace std;
const int mod=1000000007;

int dp[12345][123];
string k;
int a[12345];
int l,d;
long long ans;
long long dfs(int pos,int site,bool flag){
    //cout<<"POS:"<<pos<<"   SITE:"<<site<<"   FLAG:"<<flag<<endl;
if(pos==l+1) return dp[pos][site]=(site==0);//site等于0，dp等于1
if(!flag&&dp[pos][site]!=-1) return dp[pos][site];
int len;
if(flag) len=a[pos];
else len=9;
long long sum=0;
for(int i=0;i<=len;++i){
    sum+=dfs(pos+1,(site+i)%d,flag&&i==len);
    sum%=mod;
}
if(!flag) dp[pos][site]=sum;
return sum;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>k>>d;
    l=k.size();
    for(int i=1;i<=l;i++){
        a[i]=k[i-1]-'0';
    }

    ans=(dfs(1,0,true)-1+mod)%mod;

    cout<<ans<<endl;
    return 0;
}
