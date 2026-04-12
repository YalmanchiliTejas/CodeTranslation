#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char str[maxn];
int ans[maxn];
int n;
void solve()
{
    for(int i=2;i<n;i++)
    {
        if(ans[i]==1)
        {
            if(str[i]=='o')
            {
                ans[i+1]=ans[i-1];
            }
            else ans[i+1]=(ans[i-1]==1?2:1);
        }
        else {
            if(str[i]=='o')
            {
                ans[i+1]=(ans[i-1]==1?2:1);
            }
            else ans[i+1]=ans[i-1];
        }
    }
}
int check()
{
    int i;
    for(int i=1;i<=n;i++)
    {
        int l=i-1,r=i+1;
        if(l==0)l=n;
        if(r==n+1)r=1;
        if(ans[i]==1)
        {
            if(str[i]=='o'&&ans[l]!=ans[r])return 0;
            if(str[i]=='x'&&ans[l]==ans[r])return 0;

        }
        else
        {
            if(str[i]=='o'&&ans[l]==ans[r])return 0;
            if(str[i]=='x'&&ans[l]!=ans[r])return 0;
        }

    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    ans[1]=ans[2]=1;
    solve();
    if(check())
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]==1?'S':'W');
        printf("\n");
        return 0;
    }
    ans[1]=ans[2]=2;
    solve();
    if(check())
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]==1?'S':'W');
        printf("\n");
        return 0;
    }
    ans[1]=1;
    ans[2]=2;
    solve();
    if(check())
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]==1?'S':'W');
        printf("\n");
        return 0;
    }
    ans[1]=2;
    ans[2]=1;
    solve();
    if(check())
    {
        for(int i=1;i<=n;i++)
            printf("%c",ans[i]==1?'S':'W');
        printf("\n");
        return 0;
    }
    printf("-1\n");
    return 0;

}