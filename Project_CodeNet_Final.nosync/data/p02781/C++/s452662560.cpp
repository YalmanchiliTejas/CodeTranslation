#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define mp make_pair
const int maxn=100;
int n,m;
char a[maxn+5];
int dfs(int k,int num,bool flag=true)
{
    if(k>n) 
    {
        if(num==0) return 1;
        return 0;
    }
    int ans=dfs(k+1,num,flag&&a[k]==0);
    if(num>0)
    {
        int limit=flag?a[k]:9;
        if(limit>=1)
        {
            ans+=(limit-1)*dfs(k+1,num-1,0);
            ans+=dfs(k+1,num-1,flag);
        }
    }
    return ans;
}
int main()
{

    scanf("%s",a+1);
    n=strlen(a+1);
    scanf("%d",&m);
    for(int i=1;i<=n;++i) a[i]-='0';
    cout<<dfs(1,m)<<endl;
    return 0;
}