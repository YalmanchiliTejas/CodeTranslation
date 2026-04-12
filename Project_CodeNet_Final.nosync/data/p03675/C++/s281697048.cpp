#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int NN = 220000;
int n;
int a[NN];
deque < int > q;
int ans[NN];
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( i % 2 == 0 ) q.push_back ( a[i] );
		else q.push_front ( a[i] );
	}
	if ( n % 2 == 1 ) {
		for ( i = 1 ; i <= n ; i++ ) {
			ans[i] = q.front ();
			q.pop_front();
		}
	}
	else {
		for ( i = 1 ; i <= n ; i++ ) {
			ans[i] = q.back ();
			q.pop_back ();
		}
	}
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , ans[i] , i==n?'\n':' ' );
}
int main () {
	work ();
	return 0;
}