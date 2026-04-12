#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	std::map<int, int> mp;
	for(int i = 0; i < 12; i++) {
		int a; cin >> a;
		mp[a]++;
	}
	
	for(auto v : mp) {
		if(v.second % 4) {
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}

