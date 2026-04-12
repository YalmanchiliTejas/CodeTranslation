#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long int sum = 0;
	if( 2*c < a+b ){
		sum += min(x, y) * 2*c;
		if( x > y ){
			sum += (x-y) * ( ( 2*c < a ) ? 2*c : a );
		} else {
			// x = y のときは 0 が追加されるから問題ないはず
			sum += (y-x) * ( ( 2*c < b ) ? 2*c : b );
		}
	} else {
		sum += x*a + y*b;
	}
	cout << sum << endl;
	return 0;
}