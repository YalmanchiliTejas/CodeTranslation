#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
    char ch=gc();ll x=0;int op=1;
    for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
    for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
    return x*op;
}
#define N 105
#define mod 1000000007
int ksm(int x,int p){
    int ret=1;
    for (;p;p>>=1,x=(ll)x*x%mod) if (p&1) ret=(ll)ret*x%mod;
    return ret;
}
int n,h[N];
pii solve(int l,int r,int lim){//区间[l,r]比lim高的部分的方案数
    int mi=inf,cnt=0;pii ret;//first：存在相邻格子颜色相同情况的方案数；second：不存在的方案数（固定第一个格子的颜色）
    rep (i,l,r) if (h[i]<mi) mi=h[i],cnt=1;else if (h[i]==mi) cnt++;
    if (cnt==r-l+1){//矩形
        ret.fi=(ksm(2,r-l+1)+mod-2)%mod;
        ret.se=ksm(2,mi-lim);
        return ret;
    }
    int rest=r-l+1,s0=1,s1=1,last=0;//rest：上方没有方格的列数；s0,s1：维护上方有方格的列，当前行存在/不存在的方案数
    rep (i,l,r+1)
        if (!last&&h[i]>mi) last=i;
        else if (last&&(h[i]<=mi||i>r)){
            rest-=i-last;
            pii tmp=solve(last,i-1,mi);//子问题，递归求解
            s0=(ll)s0*(tmp.fi+2ll*tmp.se%mod)%mod;//*4是因为上一行可以取反，当前行亦然，2*2
            s1=(ll)s1*(1ll*tmp.se%mod)%mod;
            last=0;
        }
    s0=(s0+mod-s1)%mod;
    ret.fi=(ll)s0*ksm(2,rest)%mod;//如果上方方格已经存在，剩下的列随意
    ret.fi=(ret.fi+(ll)s1*(ksm(2,rest)+mod-2)%mod)%mod;//否则需要去掉两种不合法的情况
    ret.se=(ll)2ll*s1*ksm(2,mi-lim-1)%mod;//固定第一个格子（第一行）颜色
    return ret;
}
int main(){
    n=read();rep (i,1,n) h[i]=read();
    if (n==1){//注意特判
        printf("%d\n",ksm(2,h[1]));
        exit(0);
    }
    int ex=1;
    rep (i,1,n) if (h[i]>h[i-1]&&h[i]>h[i+1]){
        ex=(ll)ex*ksm(2,h[i]-max(h[i-1],h[i+1]))%mod;
        h[i]=max(h[i-1],h[i+1]);
    }
    pii ans=solve(1,n,0);
    printf("%d",(ll)ex*(ans.fi+ans.se%mod)%mod);
    return 0;
}