#include <bits/stdc++.h>
using namespace std;

#define MAX 50

int a[MAX][26];
int aa[26];

int main()
{
	int n;
	string S[MAX];

	cin >> n;
	for( int i = 0; i < n; i++ ) {
		cin >> S[i];
	}

	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < S[i].size(); j++ ) {
			a[i][S[i][j] - 'a']++;
		}
	}
	for( int i = 0; i < 26; i++ ) {
		aa[i] = INT32_MAX;
		for( int j = 0; j < n; j++ ) {
			aa[i] = min( aa[i], a[j][i] );
		}
	}

	for( int i = 0; i < 26; i++ ) {
		for( int j = 0; j < aa[i]; j++ ) {
			cout << (char)(i + 'a');
		}
	}
	cout << endl;

	return 0;
}
