#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int N;
string s;

char dp[MAX][4];

char rev( char c )
{
	if( c == 'S' ) {
		return 'W';
	}
	else {
		return 'S';
	}
}

int main() {
	cin >> N;
	cin >> s;

	dp[N -1][0] = 'S';
	dp[0][0] = 'S';
	dp[N -1][1] = 'S';
	dp[0][1] = 'W';
	dp[N -1][2] = 'W';
	dp[0][2] = 'S';
	dp[N -1][3] = 'W';
	dp[0][3] = 'W';
	for( int i = 0; i < N; i++ ) {
		int next = i + 1;
		int pre = i - 1;
		if( i == 0 ) {
			pre = N - 1;
		}
		if( i == N - 1 ) {
			next = 0;
		}
		for( int j = 0; j < 4; j++ ) {
			if( s[i] == 'o' ) {
				if( dp[i][j] == 'S' ) {
					dp[next][j] = dp[pre][j];
				}
				else {
					dp[next][j] = rev( dp[pre][j] );
				}
			}
			else {
				if( dp[i][j] == 'S' ) {
					dp[next][j] = rev( dp[pre][j] );
				}
				else {
					dp[next][j] = dp[pre][j];
				}
			}
		}
	}
	int idx = -1;
	for( int j = 0; j < 4; j++ ) {
		int flag = 0;
		for( int i = 0; i < N; i++ ) {
			int next = i + 1;
			int pre = i - 1;
			if( i == 0 ) {
				pre = N - 1;
			}
			if( i == N - 1 ) {
				next = 0;
			}
			if( s[i] == 'o' ) {
				if( dp[i][j] == 'S' ) {
					if( dp[pre][j] != dp[next][j] ) {
						flag = 1;
						break;
					}
				}
				else {
					if( dp[pre][j] == dp[next][j] ) {
						flag = 1;
						break;
					}
				}
			}
			else {
				if( dp[i][j] == 'S' ) {
					if( dp[pre][j] == dp[next][j] ) {
						flag = 1;
						break;
					}
				}
				else {
					if( dp[pre][j] != dp[next][j] ) {
						flag = 1;
						break;
					}
				}
			}
		}
		if( flag == 0 ) {
			idx = j;
			break;
		}
	}

	if( idx < 0 ) {
		cout << -1 << endl;
	}
	else {
		for( int i = 0; i < N; i++ ) {
			cout << dp[i][idx];
		}
		cout << endl;
	}

	return 0;
}
