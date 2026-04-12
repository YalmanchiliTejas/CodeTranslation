#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	string v[] = {"a", "i", "u", "e", "o"};
	set<string> st(v, v + 5);
	string s;cin >> s;
	if (st.find(s) != st.end()) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
	return 0;
}