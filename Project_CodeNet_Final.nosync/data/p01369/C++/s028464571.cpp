#include <iostream>
#include <string>
#include <set>
using namespace std;
string s_lefthand = "qwertasdfgzxcvb";
set<char> lefthand(s_lefthand.begin(), s_lefthand.end());
int main () {
	string line;
	while (cin >> line, line != "#") {
		bool prehand = (lefthand.find(line[0]) != lefthand.end());
		int count = 0;
		for (unsigned i = 0; i < line.size(); i++) {
			if ((lefthand.find(line[i]) != lefthand.end()) != prehand) {
				count++;
				prehand = !prehand;
			}
		}
		cout << count << endl;
	}
	return 0;
}