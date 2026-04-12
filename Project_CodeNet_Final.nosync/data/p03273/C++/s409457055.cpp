#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e2 + 7;
const int mod = 1e9+7;
int n,m;
char a[N][N];
bool x[N],y[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'){
                flag=0;break;
            }
        }
        if(flag)x[i]=1;
    }
    for(int j=1;j<=m;j++){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i][j]=='#'){
                flag=0;break;
            }
        }
        if(flag)y[j]=1;
    }
    for(int i=1;i<=n;i++){
        if(x[i])continue;
        bool flag=0;
        for(int j=1;j<=m;j++){
            if(y[j])continue;
            flag=1;
            putchar(a[i][j]);
        }
        if(flag)puts("");
    }
}