#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    string r, g, b;
    cin >> r >> g >> b;
    cout << ( stoi( r + g + b ) % 4 == 0 ? "YES" : "NO" ) << endl;
    return 0;
}