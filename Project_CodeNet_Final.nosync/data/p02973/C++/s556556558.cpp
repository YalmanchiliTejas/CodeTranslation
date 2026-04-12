#include <algorithm>
#include <cstdio>

using namespace std ;

const int N=2e5+10 ;

int tr[N<<1] , Siz ;
inline void build ( int n ) { for ( Siz=1 ; Siz<=n ; Siz<<=1 ); }
inline void update ( int x , int d )
{
    x+=Siz,tr[x]=max(tr[x],d);
    while ( x>1 ) x>>=1,tr[x]=max(tr[x<<1],tr[x<<1|1]);
}
inline int query ( int l , int r )
{
    int res=0 ;
    for ( l+=Siz-1,r+=Siz+1 ; l^r^1 ; l>>=1,r>>=1 )
    {
        if ( ~l&1 ) res=max(res,tr[l^1]);
        if ( r&1 ) res=max(res,tr[r^1]);
    }
    return res ;
}

int a[N] , b[N] , f[N] ;
int n , m ;
int main ()
{
    int i , T=0 ;
    scanf("%d",&n);
    for ( i=1 ; i<=n ; i++ ) scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
    for ( i=1 ; i<=n ; i++ ) a[i]=lower_bound(b+1,b+m+1,a[i])-b,T=max(T,a[i]);
    build(T);
    int res=0 ;
    for ( i=1 ; i<=n ; i++ ) f[i]=query(a[i],T)+1,update(a[i],f[i]),res=max(res,f[i]);
    printf("%d\n",res);
    return 0 ;
}