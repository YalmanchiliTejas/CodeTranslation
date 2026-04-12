#include<bits/stdc++.h>

using namespace std;

int main() {
	long long int N, M;
	cin >> N >> M;
	vector<vector<int>>D( N, vector<int>( N ) );
	for( size_t i = 0; i < M; i++ ) {
		long long int a, b;
		cin >> a >> b;
		a--; b--;
		D[a][b] = D[b][a] = 1;
	}
	vector<long long int>xx( N );
	for( size_t i = 0; i < N; i++ ) {
		xx[i] = i;
	}
	long long int count = 0;
	do {
		bool f = true;
		for( size_t i = 0; i < N - 1; i++ ) {
			if( !D[xx[i]][xx[i + 1]] ) {
				f = false;
				break;
			}
		}
		if( f ) {
			count++;
		}
	} while( next_permutation( xx.begin() + 1, xx.end() ) );
	cout << count << endl;
}