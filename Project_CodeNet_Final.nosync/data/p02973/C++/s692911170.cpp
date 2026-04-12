#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for( auto &k : a ) cin >> k;
	reverse( a.begin(), a.end() );
	map<int, int> m;
	++m[a[0]];
	int cnt = 1;
	for( int i = 1; i < n; ++i ){
		auto itr = m.upper_bound(a[i]);
		if( itr == m.end() ){
			++m[a[i]];
			++cnt;
		} else {
			int prev = itr->first;
			if( m[prev] == 1 ){
				m.erase(itr);
			} else{
				--m[prev];
			}
			++m[a[i]];
		}
	}
	cout << cnt << endl;
	return 0;
}