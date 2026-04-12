#include<cstdio>
#include<cstring>
using namespace std;
char s[10005];int n,f[10005][105][2],len,mod=1000000007;
int dfs(int nw,int res,int lim){
    int ans=0,&me=f[nw][res][lim];
    if(f[nw][res][lim]!=-1) return me;
    if(nw==len) return me=(res==0);
    int up=lim?(s[nw]-48):9;
    for(int i=0;i<=up;i++)
    ans=(ans+dfs(nw+1,(res+i)%n,lim&&(i==up)))%mod;
    return me=ans;
}
int main()
{
    scanf("%s%d",s,&n);
    len=strlen(s);
    memset(f,-1,sizeof(f));
    printf("%d",(dfs(0,0,1)-1+mod)%mod);
    return 0;
}