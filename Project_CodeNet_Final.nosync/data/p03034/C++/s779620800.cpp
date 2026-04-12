#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int visit[MAX];

int main() {
	int N;

	cin >> N;
	vector<int> s( N );
	for( int i = 0; i < N; i++ ) {
		cin >> s[i];
	}

	long long ans = 0;
	for( int c = 1; c < N; c++ ) {
		memset( visit, 0, sizeof( visit ) );
		long long f = 0;
		for( int k = 0; c * (k + 1) < N - 1; k++ ) {
			int next = N - 1 - k * c;
			if( visit[next] ) {
				break;
			}
			visit[next] = 1;
			f += s[next];
			if( visit[k * c] ) {
				break;
			}
			visit[k * c] = 1;
			f += s[k * c];
			ans = max( ans, f );
		}
	}

	cout << ans << endl;

	return 0;
}
