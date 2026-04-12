#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;

int dsu[N], x[N], y[N], ans = 0;
vector < pair < int, int > > qx, qy;
vector < pair < int, pair < int, int > > > edge;

int getPar( int v ){
    if ( dsu[v] == v ){
        return v;
    }
    return ( dsu[v] = getPar( dsu[v] ) );
}

int get_union( int a, int b ){
    a = getPar(a);
    b = getPar(b);
    if ( a != b ){
        if ( rand() & 1 ){
            swap(a,b);
        }
        dsu[a] = b;
        return 1;
    }
    return 0;
}

int main(){
    srand(127);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ){
        scanf("%d %d",&x[i],&y[i]);
        qx.pb( mp( x[i], i ) );
        qy.pb( mp( y[i], i ) );
        dsu[i] = i;
    }
    sort( qx.begin(), qx.end() );
    sort( qy.begin(), qy.end() );
    for ( int i = 0; i < size(qx) - 1; i++ ){
        edge.pb( mp( abs( qx[i].fi - qx[i+1].fi ), mp( qx[i].se, qx[i+1].se ) ) );
        edge.pb( mp( abs( qy[i].fi - qy[i+1].fi ), mp( qy[i].se, qy[i+1].se ) ) );
    }
    sort( edge.begin(), edge.end() );
    for ( int i = 0; i < size(edge); i++ ){
        if ( get_union( edge[i].se.fi, edge[i].se.se ) ){
            ans += edge[i].fi;
        }
    }
    printf("%d",ans);
    return 0;
}
