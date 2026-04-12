#include<bits/stdc++.h>

#define FOR(x,y,z) for(int x=y,x##_=z;x<=x##_;++x)
#define DOR(x,y,z) for(int x=y,x##_=z;x>=x##_;--x)
#define FOR_(x,y,z,s) for(int x=y,x##_=z;x<=x##_;x+=s)
#define FOR__(x,y,z) for(int x=y,x##_=z;x<=x##_;x<<=1)
#define EOR(x,y) for(int x##_=head[x],y=edge[x##_].e;x##_;y=edge[x##_=edge[x##_].to].e)
#define EGOR(x,y,z) for(int x##_=head[x],y=edge[x##_].e,z=edge[x##_].c;x##_;y=edge[x##_=edge[x##_].to].e,z=edge[x##_].c)

#define clr(x,y) memset(x,y,sizeof(x))
#define szf(x) sizeof(x)
#define min3(x,y,z) min(min(x,y),z)
#define max3(x,y,z) max(max(x,y),z)

#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read(x),read(y),read(z)
#define read4(x,y,z,w) read3(x,y,z),read(w)
#define reads(str) sf("%s",str)

#define ts (*this)
#define sf scanf
#define pf printf

#define ll long long
#define ull unsigned long long
#define db double
#define ct clock_t
#define ck() clock()
#define rd rand()
#define rmx RAND_MAX
#define RD T*(rd*2-rmx)


using namespace std;

template<class T>bool tomin(T &x,T y){return y<x?x=y,1:0;}
template<class T>bool tomax(T &x,T y){return x<y?x=y,1:0;}
template<class T>void read(T &x){
    char c;
    x=0;
    int f=1;
    while(c=getchar(),c<'0'||c>'9')if(c=='-')f=-1;
    do x=(x<<3)+(x<<1)+(c^48);
    while(c=getchar(),c>='0'&&c<='9');
    x*=f;
}

const db Pi=acos(-1);
const int maxn=2e5+5;
int n,m;
int A[maxn],B[maxn];
int c[maxn];
void Add(int x,int d){
    while(x){
        tomax(c[x],d);
        x&=x-1;
    }
}
int query(int x){
    int ans=0;
    while(x<=m){
        tomax(ans,c[x]);
        x+=x&-x;
    }return ans;
}
int main(){
    srand(time(NULL));
    read(n);
    FOR(i,1,n)read(A[i]),B[i]=A[i];
    sort(B+1,B+n+1);
    m=unique(B+1,B+n+1)-B-1;
    FOR(i,1,n)A[i]=lower_bound(B+1,B+m+1,A[i])-B;
    int ans=0,dp=0;
    FOR(i,1,n){
        Add(A[i],dp=query(A[i])+1);
        tomax(ans,dp);
    }
    pf("%d",ans);
    return 0;
}
