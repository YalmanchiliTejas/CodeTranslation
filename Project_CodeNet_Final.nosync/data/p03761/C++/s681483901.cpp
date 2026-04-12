#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn='z'+10;
const int inf=0x3f3f3f3f;
int ch[maxn];
int ans[maxn];
char str[100];
int n;
int main()
{
    //cout<<maxn<<endl;
    scanf("%d",&n);
    memset(ans,inf,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        memset(ch,0,sizeof(ch));
        scanf("%s",str);
        for(int i=0;i<strlen(str);i++)
        {
            ch[str[i]]++;
        }
        for(int i='a';i<='z';i++)
        {
            ans[i]=min(ans[i],ch[i]);
        }
    }
    for(int i='a';i<='z';i++)
    {
        for(int j=0;j<ans[i];j++)
            putchar(i);
    }
}
