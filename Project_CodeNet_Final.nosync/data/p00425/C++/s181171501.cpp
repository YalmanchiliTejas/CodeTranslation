#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int sum = 1;
	int  s[7] = { 0,1,2,3,4,5,6 };
	int a;
	char str[101];
	while (1) {
		sum = 1;
		cin >> a;
		if (a == 0)return 0;
		for (int i = 1; i <= a; i++) {
			cin >> str;
			if (str[0] == 'N') {
				int temp = s[1];
				s[1] = s[2];
				s[2] = s[6];
				s[6] = s[5];
				s[5] = temp;
				sum += s[1];
			}
			else if (str[0] == 'E') {
				int temp = s[1];
				s[1] = s[4];
				s[4] = s[6];
				s[6] = s[3];
				s[3] = temp;
				sum += s[1];
			}
			else if (str[0] == 'W') {
				int temp = s[1];
				s[1] = s[3];
				s[3] = s[6];
				s[6] = s[4];
				s[4] = temp;
				sum += s[1];
			}
			else if (str[0] == 'S') {
				int temp = s[5];
				s[5] = s[6];
				s[6] = s[2];
				s[2] = s[1];
				s[1] = temp;
				sum += s[1];
			}
			else if (str[0] == 'R') {
				int temp = s[2];
				s[2] = s[3];
				s[3] = s[5];
				s[5] = s[4];
				s[4] = temp;
				sum += s[1];
			}
			else if (str[0] == 'L') {
				int temp = s[2];
				s[2] = s[4];
				s[4] = s[5];
				s[5] = s[3];
				s[3] = temp;
				sum += s[1];
			}
		}

		cout << sum << endl;
		for (int i = 0; i < 8; i++) {
			s[i] = i;
		}
	}
	return 0;
}