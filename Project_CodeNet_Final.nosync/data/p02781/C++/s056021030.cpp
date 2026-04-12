#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k,l;
ll ans,po[4]={1,9,81,729},c[110][110];
char a[110];
int main()
{
    scanf("%s",a);
    int l=strlen(a);
    scanf("%d",&k);
    for(int i=0;i<=l;i++)
    {
        c[i][0]=c[i][i]=1;
    }
    for(int i=2;i<=l;i++)
    {
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    int cnt=0;
    for(int i=0;i<l&&cnt<k;i++)
    {
        if(a[i]!='0')
        {
            ans+=c[l-i-1][k-cnt]*po[k-cnt];
            if(cnt<k-1)
            {
                ans+=c[l-i-1][k-cnt-1]*(a[i]-'0'-1)*po[k-cnt-1];
            }
            else
            {
                ans+=c[l-i-1][k-cnt-1]*(a[i]-'0')*po[k-cnt-1];
            }
            cnt++;
        }
    }
    printf("%lld",ans);
}