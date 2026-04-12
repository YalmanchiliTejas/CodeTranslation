#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[105][15];
int a[105];
int k;
char s[105];
ll dfs(int len,int num,bool zero,bool equ)
{
    if (num<0) return 0;
    if (len<=0) {
        if (num==0) return 1;
        return 0;
    }
    if (!zero&&!equ&&dp[len][num]!=-1) return dp[len][num];
    int up=equ?a[len]:9;
    ll ans=0;
    for (int i=0;i<=up;i++) {
        if (i==0&&zero) ans+=dfs(len-1,num,true,equ&(i==up));
        else if (i==0) ans+=dfs(len-1,num,false,equ&(i==up));
        else ans+=dfs(len-1,num-1,false,equ&(i==up));
    }
    if (!equ&&!zero) return dp[len][num]=ans;
    return ans;
}
ll calc()
{
    scanf("%s",s);
    scanf("%d",&k);
    int len=strlen(s);
    for (int i=1;i<=len;i++) a[i]=s[len-i]-'0';
    memset(dp,-1,sizeof(dp));
    return dfs(len,k,true,true);
}
int l,r;
int main()
{
    printf("%lld\n",calc());
    return 0;
}
