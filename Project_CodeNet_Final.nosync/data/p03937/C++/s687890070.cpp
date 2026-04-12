#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
char a[50][50];
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%s",&a[i][1]);
        for(j=1;j<=m;j++){
            if(a[i][j]=='#')
                cnt++;
        }
    }
    if(cnt==n+m-1)
        printf("Possible");
    else
        printf("Impossible");
}
