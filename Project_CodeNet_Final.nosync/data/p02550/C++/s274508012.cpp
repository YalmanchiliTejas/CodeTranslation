#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, X, M;
	cin >> N >> X >> M;

	long long ans = 0;
	if( X == 0 ) {
		cout << ans << endl;
		return 0;
	}
	if( X == 1 ) {
		ans = N;
		cout << ans << endl;
		return 0;
	}
	long long A = X;
	long long a = -1;
	long long b = -1;
	long long sta;
	long long suma = X;
	long long sumb;
	set<long long> st;
	for( long long i = 1; i <= N; i++ ) {
		ans += A;
		A = A * A % M;
		if( a < 0 ) {
			if( st.count( A )  ) {
				a = i;
				sta = A;
				sumb = A;
			}
			else suma += A;
			st.insert( A );
		}
		else if( b < 0 ) {
			if( A == sta  ) {
				b = i;
				break;
			}
			else sumb += A;
		}
	}
	if( a < 0 || b < 0 ) {
		cout << ans << endl;
		return 0;
	}
	long long n = N - a;
	long long c = b - a;
	long long d = n / c;
	n = a + c * d + 1;
	ans = suma + sumb * d;
	A = sta;
	for( long long i = n; i <= N; i++ ) {
		ans += A;
		A = A * A % M;
	}
	cout << ans << endl;
}
