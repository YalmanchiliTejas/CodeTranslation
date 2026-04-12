#include <bits/stdc++.h>
#define maxs 220020
#define mme(i,j) memset(i,j,sizeof(i))
#define ll long long
using namespace std;
bool vis[maxs];
char s[maxs];
bool check(int x,int y,int len){
    vis[0]=x;
    vis[1]=y;
    for(int i=2;i<=len+1;i++){
        if(vis[i-1]){
            if(s[i-1]=='o') vis[i]=vis[i-2];
            else vis[i]=!vis[i-2];
        }else{
            if(s[i-1]=='o') vis[i]=!vis[i-2];
            else vis[i]=vis[i-2];
        }
    }
    if(vis[len]==vis[0]&&vis[len+1]==vis[1]){
        for(int i=0;i<len;i++){
            if(vis[i])
                printf("S");
            else
                printf("W");
        }
        puts("");
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        int len=n;
        s[len]=s[0];
        s[len+1]=s[1];
        s[len+2]='\0';
        bool fl=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(check(i,j,len) )
                   {
                       fl=1;
                        break;
                   }
            }
            if(fl) break;
        }
        if(!fl)
            puts("-1");
    }
    return 0;
}