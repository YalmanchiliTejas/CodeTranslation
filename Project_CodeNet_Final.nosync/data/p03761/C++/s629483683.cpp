#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> count('z'-'a'+1,(1 << 28));
	for (int q = 0; q < n; ++q) {
		string str;
		cin >> str;
		vector<int> now('z'-'a'+1,0);
		for (int i = 0; i < str.length(); ++i) {
			++now[str[i]-'a'];
		}
		for (int i = 0; i < count.size(); ++i) {
			count[i] = min(count[i],now[i]);
		}
	}

	for (int i = 0; i < count.size(); ++i) {
		for (int j = 0; j < count[i]; ++j) {
			cout << (char)('a'+i);
		}
	}
	cout << endl;

	return 0;
}
