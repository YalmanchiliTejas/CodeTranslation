#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int r,g,b;
    cin >> r >> g >> b;
    
    int ans = g * 10 + b;
    if ( ans % 4 == 0 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
