#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> a(26, 50 * n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		vector<int> b(26, 0);
		for(int j = 0; j < (int)s.size(); j++){
			b.at(s.at(j) - 'a')++;
		}
		for(int j = 0; j < 26; j++){
			a.at(j) = min(a.at(j), b.at(j));
		}
	}
	// for(int i = 0; i < 26; i++){
	// 	cout << a.at(i) << " ";
	// }
	// cout << endl;
	string ans = "";
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < a.at(i); j++){
			ans += 'a' + i;
		}
	}
	cout << ans << endl;
	return 0;
}

