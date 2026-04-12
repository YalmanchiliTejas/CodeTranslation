#include <iostream>
#include <set>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	set<int> set;
	for(int i = 0; i < s.length() - 1; i++)
		for(int j = i + 1; j < s.length(); j++){
			if (s[i] != s[j]){
				set.insert(i);
				set.insert(j);
			}
		}
	if (set.size() == 3){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
	return 0;
}