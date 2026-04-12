#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;

typedef pair<int, int> ii;

typedef vector<bool> vb;

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s, n;
	string in;
	cin >> s >> in >> n;
	string res = "";
	for ( int i = 0 ; i < s ; i++ ){
		if ( in[n-1] != in[i] ){
			res += "*";
		} else {
			res += in[i];
		}
	}
	cout << res << "\n";

	return 0;
}
