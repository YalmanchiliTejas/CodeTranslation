#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<functional>

using namespace std;

int main() {
	vector<string> S;
	vector<string> tempstr;
	vector<char> res;
	int n, mins=51;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		S.push_back(str);
	}

	int mode;
	//初期設定
	if (n == 1) {
		string str;
		str = S[0];
		tempstr.push_back(str);
		mode = 1;
	}
	else {
		string str;

		for (int i = 0; i < S[0].size(); i++) {
			for (int j = 0; j < S[1].size(); j++) {
				if (S[0][i] == S[1][j]) {
					str.push_back(S[0][i]);
					S[1][j] = '0';
					break;
				}
			}
		}
		tempstr.push_back(str);
		if (n == 2)mode = 2;
		else mode = 3;
	}

	if (mode == 3) {

		for (int f = 2; f < n; f++) {
			string str = tempstr[f - 2];
			string temp;
			
			for (int i = 0; i < str.size(); i++) {
				for (int j = 0; j < S[f].size(); j++) {
					if (str[i] == S[f][j]) {
						temp.push_back(str[i]);
						S[f][j] = '0';
						break;
					}
				}
			}
			tempstr.push_back(temp);
		}
	}

	if (mode <= 2) {
		sort(tempstr[0].begin(), tempstr[0].end());
		cout << tempstr[0] << endl;
	}
	else {
		sort(tempstr[n-2].begin(), tempstr[n-2].end());
		cout << tempstr[n-2] << endl;
	}

	return 0;
}