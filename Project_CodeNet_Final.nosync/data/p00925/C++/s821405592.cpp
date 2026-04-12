#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int cal_ltor(std::string str) {
	int num_l = 0;
	bool plus = true;
	for (int i = 0; i < str.length(); i++) {
		if ( i%2 == 0 ) {
			if ( plus ) {
				num_l += (int)(str[i] - '0');
			}
			else {
				num_l *= (int)(str[i] - '0');
			}
		}
		else {
			if ( str[i] == '+' ) {
				plus = true;
			}
			else {
				plus = false;
			}
		}
	}
	return num_l;
}

int cal_multi(std::string str) {
	int num_p = 0;
	int l = str.length();
	std::vector<bool> cal(l, true);
	for (int i = 0; i < l; i++) {
		if (str[i] == '*') {
			int end = i;
			int mv = 0;
			int pro = 1;
			while ( end < l && str[end] != '+') {
				end++;
				mv++;
			}
			for (int j = i-1; j < end; j++) {
				if ( j%2 == 0 ) {
					pro *= (int)(str[j] - '0');
					cal[j] = false;
				}
			}
			num_p += pro;
			i += end - i;
		}
	}
	for (int i = 0; i < l; i++) {
		if ( cal[i] && i%2 == 0 ) {
			num_p += (int)(str[i] - '0');
		}
	}
	return num_p;
}

int main(void) {
	std::string str;
	cin >> str;
	int num_l = cal_ltor(str);
	int num_p = cal_multi(str);

	int ans;
	cin >> ans;
	if ( ans == num_l && ans == num_p ) {
		cout << "U" << endl;
	}
	else if ( ans == num_l ) {
		cout << "L" << endl;
	}
	else if ( ans == num_p ) {
		cout << "M" << endl;
	}
	else {
		cout << "I" << endl;
	}
	return 0;
}