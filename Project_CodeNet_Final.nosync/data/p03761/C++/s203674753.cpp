# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <math.h>
# include <time.h>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define MAXN 250
# define eps 1e-3
# define MAXM 500005
# define MOD 1000000007
# define INF 1000000000
# define MIN(a,b) (a)>(b)?(b):(a)
# define MAX(a,b) (a)<(b)?(b):(a)
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FO(i,a,n) for(int i=a; i<n; ++i)
# define bug puts("H");
typedef long long LL;
typedef unsigned long long ULL;

int b[50][26],c[26],flag=0;

int main()
{
    char a[50][55];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<strlen(a[i]);j++)
            b[i][a[i][j]-97]++;
 /*   for(int i=0;i<n;i++)
    {
        printf("\ni=%d,strlen=%d",i,strlen(a[i]));
        for(int j=0;j<26;j++)
            printf("%c=%d",j+97,b[i][j]);
    }*/
    mem(c,100);
    for(int j=0,i=0;j<26;j++)
    {
        for(int i=0;i<n;i++)
            if(b[i][j]<c[j])c[j]=b[i][j];
    }
/*    for(int j=0;j<26;j++)
        printf("%c=%d\n",j+97,c[j]);*/
    for(int j=0;j<26;j++)
        for(int i=0;i<c[j];i++)
        {
            printf("%c",97+j);
        }
    cout<<endl;
    return 0;
}





















