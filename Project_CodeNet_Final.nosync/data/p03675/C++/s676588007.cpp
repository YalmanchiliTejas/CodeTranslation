#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100010;

int n;
deque<int> b;

int main() {
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) {
		int a; scanf( "%d", &a );
		if( i & 1 ) b.push_back(a);
		else b.push_front(a);
	}
	if( n & 1 ) {
		while( !b.empty() ) {
			printf( "%d ", b.back() );
			b.pop_back();
		}
	} else {
		while( !b.empty() ) {
			printf( "%d ", b.front() );
			b.pop_front();
		}
	}
	return 0;
}
