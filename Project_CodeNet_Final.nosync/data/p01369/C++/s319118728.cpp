#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		if (s == "#")break;

		string right = "yuiophjklnm";
		int ans = 0;
		int now=2;

		for (int i = 0;i < s.size();i++) {
			int a;
			size_t za = right.find(s[i]);
			if(za!=string::npos){
				a = 1;
			}
			else {
				a = 0;
			}

			if (now == 2)now = a;
			else if (now != a) {
				now = a;
				ans++;
			}

		}
		cout << ans << endl;
	}
	return 0;
}