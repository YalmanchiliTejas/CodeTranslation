#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair

const int maxn = 100005;

int tree[maxn*4];

void update( int cn, int s, int e, int x, int v )
{
    if(s==e)
    {
        tree[cn] = v;
        return;
    }
    int m = (s+e)/2, l = cn*2;
    if( x <= m ) update( l, s, m, x, v );
    else update(l+1, m+1, e, x, v);
    tree[cn] = max( tree[l], tree[l+1] );
}

int query( int cn, int s, int e, int x, int y )
{
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y ) return tree[cn];

    int m = (s+e)/2, l = cn*2;

    return max(query( l, s, m, x, y ), query( l+1, m+1, e, x, y ));
}

pii ara[maxn];
map<int,int>mm;

int main()
{
    int n;
    cin >> n;

    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i].xx;
        ara[i].yy = -i;
        mm[ ara[i].xx ];
    }
    int cnt = 1;
    for( auto it = mm.begin(); it != mm.end(); it++ )
    {
        it->yy = cnt++;
    }

    for( int i = 1; i <= n; i++  )
    {
        ara[i].xx = mm[ ara[i].xx ];
    }
    sort( ara+1, ara+n+1 );
    int ans = 1;
    for( int i = 1; i <= n; i++ )
    {
        int ind = -ara[i].yy;
        //cout << ind << endl;
        int a = query(1, 1, n, ind+1, n );
        ans = max( ans, a+1 );
        update( 1,1,n, ind, a+1 );
    }
    cout << ans << endl;


    return 0;
}
