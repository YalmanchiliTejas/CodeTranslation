#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<limits>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			cout << "Yes" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "No" << endl;
	system("pause");
	return 0;
}