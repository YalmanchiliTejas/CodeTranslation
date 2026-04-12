#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int n;
    cin >> n;
    
    ll ans = n * 800 - n / 15 * 200;
    
    cout << ans << endl;
}
