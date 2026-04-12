#include <iostream>
#include <algorithm>

#define llong long long
#define rep(i,l,n) for(int (i)=(l);(i)<(n);(i++))
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))
#define _abs(a,b) (((a)-(b))>0?((a)-(b)):((b)-(a)))

using namespace std;

int main(){
	int X; cin >> X;
	if( X >= 30 ) cout << "Yes";
	else cout << "No";
	return 0;
}