#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 110
int n,i,h,w;
char mp[N][N];
int r[N],c[N];
int main(){
    while (scanf("%d %d",&h,&w)!=EOF){
        for (int i=0;i<h;i++)
            scanf("%s",mp[i]);

        memset(r,0,sizeof r);
        memset(c,0,sizeof c);
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++)
            {
                if (mp[i][j]=='.'){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for (int i=0;i<h;i++)
        {
            bool flag = false;
            for (int j=0;j<w;j++)
                if (r[i]!=w&&c[j]!=h)
                {
                    flag = true;
                    printf("%c",mp[i][j]);
                }
            if (flag)
                printf("\n");
        }

    }
    return 0;
}
