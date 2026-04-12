#include <iostream>
#include <string>
using namespace std;

int main() {
	char left[15] = {'q', 'a', 'z', 'w', 's', 'x', 'e', 'd', 'c', 'r', 
					'f', 'v', 't', 'g', 'b'};
	char right[11] = {'y', 'h', 'n', 'u', 'j', 'm', 'i', 'k', 'o', 'l', 'p'};
	while (true) {
		string s;
		cin >> s;
		if (s[0] == '#') return 0;
		int t[s.size()] = {0};
		for (int i = 0; i < 11; i++) {
			if (s[0] == right[i]) {
				t[0] = 1;
				break;
			}
		}
		
		for (int i = 1; i < s.size(); i++) {
			for (int j = 0; j < 11; j++) {
				if (s[i] == right[j]) {
					t[i] = 1;
					break;
				}
			}
		}
		
		int count = 0;
		for (int i = 0; i < s.size() - 1; i++)
			if (t[i] != t[i+1]) count++;
		cout << count << endl;
	}
}