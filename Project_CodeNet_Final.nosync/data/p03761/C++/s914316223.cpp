#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v(26, 0);
	for( char c : s ){
		++v[c-'a'];
	}
	for( int i = 0; i < (n-1); ++i ){
		vector<int> w(26, 0);
		string t; cin >> t;
		for( char c : t ){
			++w[c-'a'];
		}
		for( int j = 0; j < 26; ++j ){
			if( v[j] > w[j] ) v[j] = w[j];
		}
	}
	string ans = "";
	for( int i = 0; i < 26; ++i ){
		for( int j = 0; j < v[i]; ++j ){
			ans += char('a'+i);
		}
	}
	cout << ans << endl;
	return 0;
}