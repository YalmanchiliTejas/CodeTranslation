#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long LD;
typedef pair<int,int> PII;
const int N=5001;
const int M=2*N;
const LL MOD1=98764321261LL;
const LL MOD=998244353LL;

inline int lowbit(int x){
    return x&(-x);
}

inline LL addmod(LL x,LL y){
    x+=y;
    if(x>=MOD)x-=MOD;
    return x;
}

struct fenwick {
    LL a[N];
    int n;
    void init(int n){
        for(int i=0;i<=n;++i)
            a[i]=0;
        this->n=n;
    }
    void add(int x,LL v) {
        for(int i=x;i<=n;i+=lowbit(i))
            a[i]+=v;
    }
    LL query(int x) {
        LL ret=0;
        for(int i=x;i;i^=lowbit(i))
            ret+=a[i];
        return ret;
    }
    void rangeadd(int l,int r,LL v) {
        add(l,v);
        add(r+1,-v);
    }
    LL rangequery(int l,int r) {
        l=max(l,1);
        r=min(r,n);
        if(r<l)return 0;
        LL ret=query(r);
        ret-=query(l-1);
        return ret;
    }
};

inline LL powmod(LL x,LL y,LL MOD){
    LL ret=1;
    while(y){
        if(y&1LL)ret=ret*x%MOD;
        x=x*x%MOD;
        y=y>>1;
    }
    return ret;
}

struct graph{
    int head[N],next[M],to[M];
    int tot;
    inline void init(int n){
        for(int i=0;i<=n;++i)
            head[i]=-1;
        tot=0;
    }
    inline void addedge(int x,int y){
        to[tot]=y;
        next[tot]=head[x];
        head[x]=tot;
        ++tot;
    }
};

struct point{
    LD x,y;
    point(){}
    point(LD x,LD y):x(x),y(y){}

    void read(){
        scanf("%lld%lld",&x,&y);
    }

    point operator + (const point &rhs)const{
        return point(x+rhs.x,y+rhs.y);
    }

    point operator - (const point &rhs)const{
        return point(x-rhs.x,y-rhs.y);
    }

    LD operator ^ (const point &rhs)const{
        return x*rhs.y-y*rhs.x;
    }

    bool operator < (const point &rhs)const{
        if(y!=rhs.y)return y<rhs.y;
        return x<rhs.x;
    }
};

LL phi(LL x)
{
    LL res=x;
    for(LL i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res=res/x*(x-1);
    return res;
}


int n,m,k,a[N];
LL f[N];

int main(){
    int cases=1;
    //init();
    //scanf("%d",&cases);
    for(int iii=1;iii<=cases;++iii){
        scanf("%d%d",&n,&m);
        LL ans=0;
        f[0]=0;
        for(int i=0;i<n;++i){
            int x;
            scanf("%d",&x);
            if(x>m)continue;
            if(x==m){
                ans=addmod(ans,(i+1)*(n-i));
                continue;
            }
            ans=addmod(ans,f[m-x]*(n-i)%MOD);
            for(int j=m-x;j>0;--j){
                f[j+x]=addmod(f[j+x],f[j]);
            }
            f[x]=addmod(f[x],i+1);
        }
        printf("%lld\n",ans);
    }



}
/*
1
4 8
1 2 1
2 3 1
3 4 1
4 1 1
1 2 2
2 3 2
3 4 2
4 1 2
*/
