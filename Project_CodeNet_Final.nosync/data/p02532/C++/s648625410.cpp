#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int N;
	cin >> N;
	vector<stack<char>>VSC( N );
	string S;
	while( cin >> S, S != "quit" ) {
		if( S == "push" ) {
			int i;
			char c;
			cin >> i >> c;
			i--;
			VSC[i].push( c );
		} else if( S == "pop" ) {
			int i;
			cin >> i;
			i--;
			cout << VSC[i].top() << endl;
			VSC[i].pop();
		} else {
			int i, j;
			cin >> i >> j;
			i--; j--;
			VSC[j].push( VSC[i].top() );
			VSC[i].pop();
		}
	}
	return 0;
}