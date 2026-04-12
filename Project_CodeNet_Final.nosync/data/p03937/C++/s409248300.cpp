#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+500;
char st[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",st+1);
        for(int j=1;j<=m;j++)cnt+=st[j]=='#';
    }
    puts(cnt==n+m-1?"Possible":"Impossible");
}