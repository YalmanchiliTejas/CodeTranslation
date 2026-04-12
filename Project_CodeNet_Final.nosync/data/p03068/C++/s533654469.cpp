#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
	int n, k;
	string ss;
	
	cin >> n >> ss >> k;

	char s = ss[k-1];

	REP(i, n) {
		if (s != ss[i])		ss[i] = '*';
	}
	
	cout << ss << endl;
}
