#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	string str;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> str;
		for(int j = 0; j < m; ++j){
			if(str[j] == '#') ++ mp[i+j]; } }

	cout << (all_of(begin(mp), end(mp), [](const pair<int, int>& p){ return p.second == 1; }) ?
			"Possible" :
			"Impossible") << endl;

	return 0; }
