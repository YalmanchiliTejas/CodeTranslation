#include <bits/stdc++.h>
using namespace std;
const int N = 300000;

int n;

struct tData {
    int x, id, ans;
} a[N];

inline bool cmp_x( tData x, tData y ) { return x.x < y.x; }
inline bool cmp_id( tData x, tData y ) { return x.id < y.id; } 

int main()
{
    scanf( "%d", &n );
    for( int i = 1; i <= n; i ++ )
        scanf( "%d", &a[i].x );
    for( int i = 1; i <= n; i ++ )
        a[i].id = i;

    sort( a+1, a+1+n, cmp_x );
    int mid = n / 2;
    for( int i = 1; i <= mid; i ++ )
        a[i].ans = a[mid+1].x;
    for( int i = mid+1; i <= n; i ++ )
        a[i].ans = a[mid].x;

    sort( a+1, a+1+n, cmp_id);
    for( int i = 1; i <= n; i ++ )
        printf( "%d\n", a[i].ans );

    return 0;
}