#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL maxn = 100+100;
int vis[maxn];
char a[maxn][maxn];
int len[maxn];
int ans[maxn];
int ans1[maxn];
int ans2[maxn];
int main()
{
    int n;
    cin>>n;
    string sum="";
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        len[i]=strlen(a[i]);
    }
    for(int i=49;i<=74;i++)
    {
        ans2[i]=10000;//´æ´¢¸öÊý
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            ans1[a[i][j]-'0']++;
        }
        for(int j=49;j<=74;j++)
        {
            ans2[j]=min(ans2[j],ans1[j]);
        }
        memset(ans1,0,sizeof(ans1));
    }
    int flag=0;
    for(int i=49;i<=74;i++)
    {
        for(int j=0;j<ans2[i];j++)
        {
            printf("%c",i+'0');
            flag=1;
        }
    }
    if(flag)
    cout<<""<<endl;


}
