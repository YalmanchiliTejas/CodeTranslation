#include <bits/stdc++.h>
using namespace std;

int f[2][2] = {{1,1},{0,1}};

int main() {
	int N;
	cin >> N;
	
	vector< int > a(N);
	for (int i=0; i<N; ++i) {
		char c;
		cin >> c;
		if (c == 'T') a[i] = 1;
		else a[i] = 0;
	}
	
	int c = f[a[0]][a[1]];
	for (int i=2; i<N; ++i) c = f[c][a[i]];
	puts(c == 0 ? "F" : "T");
}
