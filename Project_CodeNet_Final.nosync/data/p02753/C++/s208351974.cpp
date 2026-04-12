#include <bits/stdc++.h>

using namespace std;


#define PI 3.14159265
#define int long long



main(){

	string s; cin >> s;

	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());

	cout << (s.size() == 1 ? "No" : "Yes") << endl;
	
	
	
	return 0;
}