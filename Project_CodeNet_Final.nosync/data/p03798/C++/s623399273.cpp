#include <iostream>
#include <string>
#include <vector>
using namespace std;

char opposite(char a)
{
	if(a == 'W') return 'S';
	else return 'W';
}

char judgeByPreviousTwo(char a, char b, char c)
{
	if(b == 'S'){
		if(c == 'o') return a;
		if(c == 'x') return opposite(a);
	}else if(b == 'W'){
		if(c == 'o') return opposite(a);
		if(c == 'x') return a;
	}
}

char checkValidity(char a, char b, char c)
{
	if(b == 'S'){
		if(a == c) return 'o';
		else return 'x';
	}else{
		if(a != c) return 'o';
		else return 'x';
	}
}

int ind(int j, int size)
{
	if(j < 0) return size + j;
	if(j >= size) return j - size;
	return j;
}

int main()
{
	int n = 0; cin >> n;
	string s; cin >> s;

	vector<string> initial_patterns = {
		"SS", "SW", "WS", "WW",
	};

	bool found = false;
	string ans(n, '0'); 		
	for(int i = 0; i < initial_patterns.size(); i++){
		ans.replace(n - 2, 2, initial_patterns[i]);
		string check_validity(n, '0');
		for(int j = 0; j < n; j++){
			if(j < n - 2) ans[j] = judgeByPreviousTwo(ans[ind(j - 2, n)], ans[ind(j - 1, n)], s[ind(j - 1, n)]);
			check_validity[ind(j - 1, n)] = checkValidity(ans[ind(j - 2, n)], ans[ind(j - 1, n)], ans[ind(j, n)]);
			if(check_validity[ind(j - 1, n)] != s[ind(j - 1, n)]) break;
			if(j == n - 1) found = true;
		}
		// cout << ans << endl;
		// cout << check_validity << endl;
		if(found) break;
	}
	if(found) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}