#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++) 
#define ltype int
#define rep(i,j,k) for(ltype (i)=(j);(i)<=(k);(i)++)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,
mod=1000000007;
const double pi=3.1415926535897932,
eps=1e-6;
int n,a[100005],f[100005],ans;map<int,int> m;
struct segtree{
    int dat[262150],n;
    void build(int nn)
    {
        n=1;
        while(n<=nn) n<<=1;
        for(int i=0;i<2*n-1;i++) dat[i]=-inf;
    }
    void update(int k,int a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[(k<<1)+1],dat[(k<<1)+2]);
        }
    }
    int query(int l,int r){
        return query(l,r+1,0,1,n);
    }
    int query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l) return -inf;
        if(a<=l&&r<=b) return dat[k];
        return max(query(a,b,(k<<1)+1,l,(l+r)>>1),query(a,b,(k<<1)+2,(l+r)>>1,r));
    }
}seg;
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i),m[a[i]]=0;int b=0;
    itrm(it,m) it->se=++b;
    seg.build(b);
    rep(i,1,n) a[i]=m[a[i]];
    seg.update(b,0);
    rep(i,1,n){
        f[i]=seg.query(a[i],b)+1;
        seg.update(a[i],f[i]);
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}