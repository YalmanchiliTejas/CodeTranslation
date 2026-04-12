#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> vec;
	set<int> indices;
	for(int i = 0; i < h; i++) {
		string s;
		cin >> s;
		if(s.find('#') != string::npos) {
			vec.push_back(s);
			for(int j = 0; j < s.length(); j++){
				if(s[j] == '#') {
					indices.insert(j);
				}
			}
		}
	}
	for(int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].length(); j++) {
			if(indices.count(j)) {
				cout << vec[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
