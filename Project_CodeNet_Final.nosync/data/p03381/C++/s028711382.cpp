#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	int X[200005], sorted[200005];
	
	cin >> N;
	for ( int i = 0; i < N; i++ ) {
		cin >> X[i];
		sorted[i] = X[i];
	}
	sort(sorted, sorted + N);
	int a = sorted[N / 2 - 1], b = sorted[N / 2];

	for ( int i = 0; i < N; i++ ) {
		if ( X[i] <= a ) {
			cout << b << endl;
		} else {
			cout << a << endl;
		}
	}

	return (0);
}
