#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> a( H * W );
    REP( i, H )
    {
        cin >> a[ i ];
    }
    vector<int> ri( H ), cj( W );
    REP( i, H )
    {
        REP( j, W )
        {
            if( a[ i ][ j ] == '#' )
            {
                ri[ i ]++;
                cj[ j ]++;
            }
        }
    }
    REP( i, H )
    {
        REP( j, W )
        {
            if( ri[ i ] > 0 && cj[ j ] > 0 )
            {
                cout << a[ i ][ j ];
            }
        }
        if( ri[ i ] != 0 ) cout << endl;
    }
    return 0;
}