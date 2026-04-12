#include<bits/stdc++.h>
/*
*/

using namespace std;


int main() {
	long long int N;
	cin >> N;
	vector<long long int>D( N );
	list<long long int>ans;
	for( long long int i = 0; i < N; i++ ) {
		long long int X;
		cin >> X;
		if( i % 2 ) {
			ans.push_back( X );
		} else {
			ans.push_front( X );
		}
	}
	if( N % 2 ) {
		auto now = ans.begin();
		for( size_t i = 0; i < N; i++ ) {
			cout << *now;
			now++;
			if( i == N - 1 ) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	} else {
		auto now = ans.rbegin();
		for( size_t i = 0; i < N; i++ ) {
			cout << *now;
			now++;
			if( i == N - 1 ) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
	}

}