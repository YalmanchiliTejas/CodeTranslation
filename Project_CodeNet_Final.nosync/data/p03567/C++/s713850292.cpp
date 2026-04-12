#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	const int n = s.size();
	bool answer = false;
	for(int i = 0; i + 1 < n; ++i){
		if(s[i] == 'A' && s[i + 1] == 'C'){ answer = true; }
	}
	cout << (answer ? "Yes" : "No") << endl;
	return 0;
}

