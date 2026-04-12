#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	int answer;

	cin >> str >> answer;

	bool flagL = false;
	bool flagM = false;

	int ansL = str[0] - '0';

	for (int i = 1; i < str.size(); i += 2) {
		if (str[i] == '+') {
			ansL += str[i + 1] - '0';
		}
		else if (str[i] == '*') {
			ansL *= str[i + 1] - '0';
		}
	}

	if (ansL == answer) {
		flagL = true;
	}

	int ansM = 0;
	vector<int> num;
	vector<char> calc;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			calc.push_back(str[i]);
		}
		else if (str[i] == '*') {
			calc.push_back(str[i]);
		}
		else {
			num.push_back(str[i] - '0');
		}
	}

	while (true) {
		bool flag = false;

		for (int i = 0; i < calc.size(); i++) {
			if (calc[i] == '*') {
				num[i] = num[i] * num[i + 1];
				num.erase(num.begin() + i + 1);
				calc.erase(calc.begin() + i);
				flag = true;
				break;
			}
		}

		if (flag == true) {
			continue;
		}
		else {
			for (int i = 0; i < num.size(); i ++) {
				ansM += num[i];
			}

			if (ansM == answer) {
				flagM = true;
			}

			break;
		}
	}

	if (flagL == true && flagM == true) {
		cout << "U" << endl;
	}
	else if (flagL == true) {
		cout << "L" << endl;
	}
	else if (flagM == true) {
		cout << "M" << endl;
	}
	else {
		cout << "I" << endl;
	}

	return 0;
}