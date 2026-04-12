#include <bits/stdc++.h>
using namespace std;

string getFact(int num)
{
	if ( num % 3 == 0 ) {
		if ( num % 5 == 0 ) {
			return ("FizzBuzz");
		} else {
			return ("Fizz");
		}
	} else if ( num % 5 == 0 ) {
		return ("Buzz");
	} else {
		return (to_string(num));
	}
}

int main()
{
	int M, N;

	while ( cin >> M >> N, M || N ) {
		string S;
		int pos = 0, fail = 0;
		bool lock = false;
		bool flag[1005] = {};

		for ( int i = 0; i < N; i++ ) {
			cin >> S;
			if ( !lock ) {
				if ( S != getFact(i + 1) ) {
					flag[pos] = true;
					fail++;
				}
				if ( fail == M - 1 ) {
					lock = true;
				}
			}
			(pos += 1) %= M;
			while ( flag[pos] ) {
				(pos += 1) %= M;
			}
		}
		//out
		vector < int > ans;
		for ( int i = 0; i < M; i++ ) {
			if ( !flag[i] ) {
				ans.push_back(i + 1);
			}
		}
		cout << ans[0];
		for ( int i = 1; i < ans.size(); i++ ) {
			cout << " " << ans[i];
		}
		cout << endl;
	}

	return ( 0 );
}

