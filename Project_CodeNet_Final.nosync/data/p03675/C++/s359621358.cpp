#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> b;
	int btmp;
	if(n%2 ==0)
		for (int i = 0; i < n; i++) {
			cin >> btmp;
			if (i % 2 == 0)
				b.push_back(btmp);
			else
				b.insert(b.begin(), btmp);
		}
	else
		for (int i = 0; i < n; i++) {
			cin >> btmp;
			if (i % 2 != 0)
				b.push_back(btmp);
			else
				b.insert(b.begin(), btmp);
		}
	auto itr = b.begin();
	string out = "";
	while (itr != b.end()) {
		string s = (itr + 1 == b.end()) ? "" : " ";
		out += to_string(*itr) + s;
		itr++;
	}
	cout << out;
	return 0;
}
