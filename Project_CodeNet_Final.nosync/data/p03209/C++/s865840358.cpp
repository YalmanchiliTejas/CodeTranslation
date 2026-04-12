#include<bits/stdc++.h>
namespace ZDY{
    #define res register
    #define ri res ll
    #define ll unsigned long long
    #define db double
    #define sht short
    #define il inline
    #define MB template <class T>
    #define Fur(i,x,y) for(ri i=x;i<=y;i++)
    #define fur(i,x,y) for(i=x;i<=y;i++)
    #define Fdr(i,x,y) for(ri i=x;i>=y;i--)
    #define clr(x,y) memset(x,y,sizeof(x))
    #define cpy(x,y) memcpy(x,y,sizeof(x))
    #define fl(i,x) for(ri i=head[x],to;to=e[i].to,i;i=e[i].nxt)
    #define inf 21474836473
    #define fin(s) freopen(s".in","r",stdin)
    #define fout(s) freopen(s".out","w",stdin)
    #define l2(n) (ceil(log2(n)))
    MB il T ABS(T x){return x>0?x:-x;}
    MB il T MAX(T x,T y){return x>y?x:y;}
    MB il T MIN(T x,T y){return x<y?x:y;}
    MB il T GCD(T x,T y){return y?GCD(y,x%y):x;}
    //#define gc() getchar()
    il char gc(){static char buf[1000000],*s,*t;return s==t?(((t=(s=buf)+fread(buf,1,1000000,stdin))==s)?-1:*s++) : *s++;}
    il int gi(){int x=0,f=0;char c=gc();while(c<'0'||'9'<c){if(c=='-')f=!f;c=gc();}while('0'<=c&&c<='9'){x=x*10+c-48;c=gc();}return f?(-x):x;}
}using namespace ZDY;using namespace std;
#define N 100010
ll l[55],n,k,s[55],ans=0;
il void cl(){
    l[0]=s[0]=1;
    Fur(i,1,50)l[i]=(l[i-1]<<1)+3,s[i]=(s[i-1]<<1)+1;
}
#define chk if(!k){cout<<ans<<endl;exit(0);}
il void dfs(ll d){
    if(d==0){
        chk;
        cout<<ans+1<<endl;exit(0);
    }
    chk;//  _
    k--;chk;// .
    if(k>=l[d-1]){ans+=s[d-1],k-=l[d-1];chk;}// .bk
    else dfs(d-1);
    ans++;k--;chk;// .bk$
    if(k>=l[d-1]){ans+=s[d-1],k-=l[d-1];chk;}// .bk&bk
    else dfs(d-1);
    k--;chk;// .bk&bk.
}
int main(){
    cl();
    cin>>n>>k;
    dfs(n);
}