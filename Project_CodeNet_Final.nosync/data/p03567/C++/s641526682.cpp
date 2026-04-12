#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

typedef unsigned long long LL;

using namespace std;

int main() {
	string S;
	cin >> S;
	bool flag = false;
	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] == 'A'&&S[i + 1] == 'C') {
			flag = true;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}