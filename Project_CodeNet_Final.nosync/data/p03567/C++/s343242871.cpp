#include<cstdio>
#include<cmath>
#include<iomanip>
#include<sstream>
#include<stack>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	char in='-', in2='-';
	bool judge = false;
	while (in2 != 'C') {
		while (in != 'A') {
			cin >> in;
			if (cin.peek() == '\n')
				break;
		}
		if (cin.peek() == '\n')
			break;
		cin >> in2;
		if (in2 != 'C') {
			if (in2 == 'A')
				in = 'A';
			else
				in = '-';
		}
		else {
			judge = true;
			break;
		}
		if (cin.peek() == '\n')
			break;
	}
	if (judge == true)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}