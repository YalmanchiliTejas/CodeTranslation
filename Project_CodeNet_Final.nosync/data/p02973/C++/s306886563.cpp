#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	deque < int > d;

	cin >> N;
	for ( int i = 0; i < N; i++ ) {
		int A, p;
		cin >> A;
		p = lower_bound(begin(d), end(d), A) - begin(d);
		if ( p == 0 ) d.push_front(A);
		else d[p - 1] = A;
	}

	cout << d.size() << endl;

	return ( 0 );
}
