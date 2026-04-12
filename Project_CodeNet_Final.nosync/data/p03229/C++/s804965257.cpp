#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int N;
long long A[MAX_N];

int main()
{
	cin >> N;
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	sort( A, A + N );

	long long ans1 = 0;
	int i = 0;
	int j = N - 1;
	int flag = 0;
	while( i < j ) {
		ans1 += abs(A[i] - A[j]);
		if( flag ) {
			j -= 2;
			flag = 0;
		}
		else {
			i += 2;
			flag = 1;
		}
	}
	i = 0;
	j = N - 2;
	flag = 0;
	while( i < j ) {
		ans1 += abs(A[i] - A[j]);
		if( flag ) {
			j -= 2;
			flag = 0;
		}
		else {
			if( i == 0 ) {
				i++;
			}
			else {
				i += 2;
			}
			flag = 1;
		}
	}

	long long ans2 = 0;
	i = N - 1;
	j = 0;
	flag = 0;
	int cnt = 0;
	while( i > j && ++cnt <= N / 2 ) {
		ans2 += abs(A[i] - A[j]);
		if( flag ) {
			j += 2;
			flag = 0;
		}
		else {
			if( i == N - 1 ) {
				i--;
			}
			else {
				i -= 2;
			}
			flag = 1;
		}
	}
	i = N - 1;
	j = 1;
	flag = 0;
	while( i > j ) {
		ans2 += abs(A[i] - A[j]);
		if( flag ) {
			j += 2;
			flag = 0;
		}
		else {
			i -= 2;
			flag = 1;
		}
	}

	cout << max( ans1, ans2 ) << endl;

	return 0;
}
