#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    #ifdef LOCAL
        freopen("E.txt","r",stdin);
    #endif
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
    bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
int readint(){
    int val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
int d[13][13];
struct edge{
    int x,y,z;
}e[2333];
bool vis[103][103];
int main(){
    init();
    int a=readint(),b=readint(),cur=0;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            d[i][j]=readint();
    // memset(vis,-1,sizeof(vis));
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=100;k++){
                bool flag=0;
                for(int o=1;o<=a;o++)
                    for(int t=1;t<=b;t++){
                        if (i*o+j*t+k<d[o][t]){
                            flag=1;
                            goto hell;
                        }
                    }
                hell:;
                if (flag)
                    continue;
                flag=0;
                for(int o=1;o<=a;o++)
                    for(int t=1;t<=b;t++)
                        if (!vis[o][t] && i*o+j*t+k==d[o][t])
                            vis[o][t]=flag=1;
                if (flag)
                    e[++cur]=(edge){i,j,k};
            }
    // puts("WTF");
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            if (!vis[i][j])
                return puts("Impossible"),0;
    puts("Possible");
    printf("%d %d\n",202,cur+200);
    for(int i=0;i<100;i++)
        printf("%d %d X\n",i+1,i+2);
    for(int j=1;j<=100;j++)
        printf("%d %d Y\n",j+102,j+101);
    for(int i=1;i<=cur;i++)
        printf("%d %d %d\n",e[i].x+1,e[i].y+102,e[i].z);
    puts("1 102");
    
    
}