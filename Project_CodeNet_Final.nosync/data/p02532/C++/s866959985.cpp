#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	int n;
	cin >> n;

	vector<vector<char>> array (n);
	vector<char> ans;

	while(1) {
		int n1, n2;
		char keep, c;
		cin >> str;
		if(str == "quit") {
			break;
		} else if(str == "push") {
			cin >> n1 >> c;
			array[n1 - 1].push_back(c);
		} else if(str == "pop") {
			cin >> n1;
			keep = array[n1 - 1].back();
			ans.push_back(keep);
			array[n1 - 1].pop_back();
		} else if(str == "move") {
			cin >> n1 >> n2;
			keep = array[n1 - 1].back();
			array[n1 - 1].pop_back();
			array[n2 - 1].push_back(keep);
		}
	}
	int len = ans.size();
	for(int i = 0; i < len; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}