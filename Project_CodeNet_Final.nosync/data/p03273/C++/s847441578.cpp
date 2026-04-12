#include<bits/stdc++.h>
#define LL long long
#define Max 100005
#define Mod 1e9+7
const LL mod=1e9+7;
const LL inf=0x3f3f3f3f;
using namespace std;
int n,m;
int vis[105][105];
char a[105][105];
void find_row()
{
  for(int i=0;i<n;i++){
        int t=0;
    for(int j=0;j<m;j++){
        if(a[i][j]=='.')
            t++;
    }
    if(t==m){
        for(int k=0;k<m;k++)
            vis[i][k]=1;
    }
  }
}
void find_col()
{
    for(int i=0;i<m;i++){
            int t=0;
        for(int j=0;j<n;j++){
            if(a[j][i]=='.')
                t++;
        }
        if(t==n){
            for(int k=0;k<n;k++)
                vis[k][i]=1;
        }
    }
}
void print_ans()
{
    for(int i=0;i<n;i++){
            int t=0;
        for(int j=0;j<m;j++){
            if(!vis[i][j])
                printf("%c",a[i][j]),t++;
        }
    if(t)
        printf("\n");
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    find_col();
    find_row();
    print_ans();
    return 0;
}
