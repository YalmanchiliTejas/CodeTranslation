#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s){
		if (s == "#")break;
		int sum = 0;
		const string left_hand = "qwertasdfgzxcvb";
		//true false
		bool a,b;
		if ((int)left_hand.find(s[0]) != -1)
			a = true;
		else a = false;
		for (int i = 1; i < s.size(); i++){
			if ((int)left_hand.find(s[i]) != -1)
				b = true;
			else b = false;
			if (a != b)sum++;
			a = b;
		}
		cout << sum << endl;
	}
	return 0;
}