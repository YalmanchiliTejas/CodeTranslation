#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int cnt{};
    for( int i = 0; i <= 100000; i++ )
    {
        if( Y * i + Z * ( i + 1 ) <= X )
        {
            cnt = i;
        }
        else
        {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}