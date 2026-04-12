#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b , c , x , y;
    cin >> a >> b >> c >> x >> y;
	int n = 1e9;
   	for( int i = 0 ; i <= max( x , y ) ; i++ ) {
    	int d = max( x - i , 0 ) * a + max( y - i , 0 ) * b + i * 2 * c;
     	n = min( n , d );
    }
    cout << n;
}
