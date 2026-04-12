#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=1e7+10,mod=998244353;
int n,fac[maxn],inv[maxn],g[maxn],ans;
int mul(int x,int y){return 1ll*x*y-1ll*x*y/mod*mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int del(int x,int y){return x-y<0?x-y+mod:x-y;}
int mi(int a,int b){int ans=1;while(b){if(b&1)ans=mul(ans,a);b>>=1,a=mul(a,a);}return ans;}
int C(int n,int m){return mul(fac[n],mul(inv[m],inv[n-m]));}
int main(){
    read(n);fac[0]=inv[0]=g[0]=1;
    for(rg int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i),g[i]=mul(g[i-1],2);
    inv[n]=mi(fac[n],mod-2);
    for(rg int i=n-1;i;i--)inv[i]=mul(inv[i+1],i+1);
    for(rg int i=n/2+1;i<=n;i++)
	ans=add(ans,mul(C(n,i),g[n-i]));
    printf("%d\n",del(mi(3,n),mul(ans,2)));
}
