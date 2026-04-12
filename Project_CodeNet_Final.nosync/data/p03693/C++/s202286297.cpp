#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e3 + 5;
const double PI = acos(-1.0);

int main( void ) {
    
    int x, y, z;
    cin >> x >> y >> z;
    
    cout << ( ( (x * 100 + y * 10 + z) % 4 == 0 ) ? "YES" : "NO" );
    
    return 0;
}
