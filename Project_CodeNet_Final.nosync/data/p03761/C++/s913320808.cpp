#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <utility>

int main(void){
	using namespace std;
	
	// index
	array<int, 26> a;
	for(int i = 0; i < 26; ++i){
		a[i] = 51;
	}
	
	int n;
	cin >> n;

	vector<string> s;
	s.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
		
		for(int j = 0; j < 26; ++j){
			int tmp = count(s[i].begin(), s[i].end(), 'a' + j);
			a[j] = min(tmp, a[j]);
		}
	}
	
	// DEBUG
	/*
	for(int i = 0; i < 26; ++i){
		char test = 'a' + i;
		cout << test << " : " << a[i] << endl;
	}
	*/
	
	string ans;
	for(int i = 0; i < 26; ++i)
		for(int j = 0; j < a[i]; ++j)
			ans += 'a' + i;
	cout << ans << endl;
	
	return 0;
}