#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++) 
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int N, M;
vector<vector<int>> v( 8 + 1 , vector<int>( 8 + 1, 0 ) );
vector<int> visited( 8 + 1, 0 );
bool flag = true;
int res{};
void dfs( int i )
{
    //始点 -> 1 をset
    visited[ i ] = 1;
    REP2( j, 1, N + 1 )
    {
        if( v[ i ][ j ] == 1 && visited[ j ] == 0 )
        {
            flag = true;
            dfs( j );
            visited[ j ] = 0;
        }
        if( !visited[ j ] )
        {
            flag = false;
        }
    }
    if( flag )
    {
        res++;
    }
}
int main()
{
    cin >> N >> M;
    
    int A, B;
    REP2( i, 1, M + 1 )
    {
        cin >> A >> B;
        REP2( j, 1, M + 1 )
        {
            v[ A ][ B ] = 1;
            v[ B ][ A ] = 1;
        }
    }
    dfs( 1 );
    cout << res << endl;
    return 0;
}