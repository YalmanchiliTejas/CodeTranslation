//2019.5.19 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0,ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline LL Read() {
    RG LL s=0;
    res ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5+10;
const int kcz=1e9+7;
namespace MAIN {
    int n,m,dp[N],p=1,sum[N],ans;
    char str[N];
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:x+y;
    }
    inline int mul(const res &x,const res &y){
        return int(1LL*x*y%kcz);
    }
    inline void MAIN(){
        n=read(),m=read(),scanf("%s",str+1);
        for(;p<=m;p++)if(str[p]!=str[1])break;
        res o=p;
        p--,dp[0]=sum[0]=1;
        if(p==m){
            ans=1;
            for(res i=0;i<=n;i++){
                if(i>=2)dp[i]=sum[i-2];
                sum[i]=Add(sum[i-1],dp[i]);
                if(n-i>=2)add(ans,mul(dp[i],n-i));
            }
            printf("%d\n",ans);
            return;
        }
        if(n&1){puts("0");return;}
        if(p%2==0)p++;
        for(res t=0,i=o;i<=m;i++)
            if(str[i]==str[1])t++;
            else {
                if(t&1)p=min(p,t);
                t=0;
            }
        n>>=1,p=(p+1)>>1;
        for(res i=0;i<=n;i++){
            if(i)dp[i]=Add(sum[i-1],kcz-(i-p>0?sum[i-p-1]:0)),sum[i]=Add(sum[i-1],dp[i]);
            if(n-i<=p)add(ans,mul(n-i,dp[i]<<1));
        }
        printf("%d\n",ans);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("graph.in","r",stdin);
//    freopen("graph.out","w",stdout);
    MAIN::MAIN();
    return 0;
}