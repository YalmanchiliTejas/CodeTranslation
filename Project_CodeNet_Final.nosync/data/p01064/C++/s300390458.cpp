#include <bits/stdc++.h>
using namespace std;

long long int a, d;
struct query
{
	int x, y, z;
};

vector<query>all;

long long int saiki( long long int K, long long int N ) {
	if( N == all.size() ) {
		return a + d*K;
	}
	query now = all[N];
	if( now.y <= K&&K <= now.z ) {
		if( now.x == 0 ) {
			long double center = (now.y + now.z) / 2;
			K = center * 2 - K;

		} else if( now.x == 1 ) {
			return 1 + saiki( K, N + 1 );

		} else {
			return saiki( K, N + 1 ) / 2;
		}
	}
	return saiki( K, N + 1 );
}

int main() {
	long long int N;
	cin >> N;
	cin >> a >> d;

	long long int M;
	cin >> M;
	all.resize( M );
	for( size_t i = 0; i < M; i++ ) {
		long long int x, y, z;
		cin >> x >> y >> z;
		all[i].x = x;
		y--;
		all[i].y = y;
		z--;
		all[i].z = z;
	}
	reverse( all.begin(), all.end() );
	long long int K;
	cin >> K;
	K--;
	cout << saiki( K, 0 ) << endl;
}