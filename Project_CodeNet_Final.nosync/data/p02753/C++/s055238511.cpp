#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

string s;

int main(){
	
	cin >> s;
	for ( int i = 1; i < 3; i++ ){
		if ( s[i] != s[i-1] ){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}