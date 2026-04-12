#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;

typedef pair<int, int> ii;

typedef vector<bool> vb;

int main( int argc, char *argv[] ) {
	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int max, n, tmp;
	max = 0;
	n = 0;
	for ( int i = 0 ; i < T ; i++ ) {
		cin >> tmp;
		if ( tmp >= max ){
			max = tmp;
			n++;
		}
	}
	std::cout << n << std::endl;
}
