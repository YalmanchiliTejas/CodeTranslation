#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	map<char, int> occ;
	for(int i = 'a'; i <= 'z'; i++) occ[i] = 100000;
	for(int i = 0; i < n; i++){
		map<char, int> now;
		for(int j = 'a'; j <= 'z'; j++) now[j] = 0;
		string j; cin >> j;
		for(auto c : j) now[c]++;
		for(auto c : now) occ[c.first] = min(occ[c.first], c.second);
	}
	for(auto e : occ) while(e.second--) cout << e.first;
	cout << endl;
	return 0;
}
