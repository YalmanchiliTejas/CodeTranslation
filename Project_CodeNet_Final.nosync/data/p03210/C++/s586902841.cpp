#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
const int MOD = 1000000007;
const int INF = 1e9;

#define EPS (1e-7)
#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()
#define s_exists(elem, s) s.find(elem)!=s.end()
#define tasu(x, y) (x+y)%MOD
#define kake(x, y) (x*y)%MOD

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm( long m, long n ){
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;

	return ((m / gcd(m, n)) * n);
}


int main(){
	int X;
	cin >> X;

	if(X==7 || X== 5 ||X==3){
		cout << "YES" << endl;
	}  else {
		cout << "NO" << endl;
	}

	return 0;
}