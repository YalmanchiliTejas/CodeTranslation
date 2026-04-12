#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<char> mis(26), com(26);
	string tmp;
	int n;
	cin >> n;
	cin >> tmp;
	for ( auto l : tmp )
		com[l-'a']++;
	for ( int i = 1 ; i < n ; i++ ){
		cin >> tmp;
		mis = com;
		com = vector<char>(26);
		for ( auto l : tmp ) {
			if ( mis[l-'a'] > 0 ){
				mis[l-'a']--;
				com[l-'a']++;
			}
		}
	}
	for ( int i = 0 ; i < com.size() ; i++ ){
		for ( int j = 0 ; j < com[i] ; j++ ){
			cout << char(i + 'a');
		}
	}
	cout << "\n";

	return 0;
}
