#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int alphabet[2][30];

vector<string>ans;

string tostr(int a);

int main() {

	int n;

	scanf("%d",&n);

	string S;

	int i,j;

	for (i = 0; i < n; i++) {
		cin >> S;
		memset(alphabet[1],0,sizeof(alphabet[1]));
		for (j = 0; j < S.size(); j++) {
			alphabet[1][S[j] - 'a']++;
		}
		if (i == 0) {
			for (j = 0; j < S.size(); j++) {
				alphabet[0][S[j] - 'a']++;
			}
		}
		else {
			for (j = 0; j < 30; j++) {
				alphabet[0][j] = min(alphabet[0][j], alphabet[1][j]);
			}
		}
	}


	for (i = 0; i < 26; i++) {
		for (j = 0; j < alphabet[0][i]; j++) {
			if (i == 0) {
				ans.push_back("a");
			}
			else if (i == 1) {
				ans.push_back("b");
			}
			else if (i == 2) {
				ans.push_back("c");
			}
			else if (i == 3) {
				ans.push_back("d");
			}
			else if (i == 4) {
				ans.push_back("e");
			}
			else if (i == 5) {
				ans.push_back("f");
			}
			else if (i == 6) {
				ans.push_back("g");
			}
			else if (i == 7) {
				ans.push_back("h");
			}
			else if (i == 8) {
				ans.push_back("i");
			}
			else if (i == 9) {
				ans.push_back("j");
			}
			else if (i == 10) {
				ans.push_back("k");
			}
			else if (i == 11) {
				ans.push_back("l");
			}
			else if (i == 12) {
				ans.push_back("m");
			}
			else if (i == 13) {
				ans.push_back("n");
			}
			else if (i == 14) {
				ans.push_back("o");
			}
			else if (i == 15) {
				ans.push_back("p");
			}
			else if (i == 16) {
				ans.push_back("q");
			}
			else if (i == 17) {
				ans.push_back("r");
			}
			else if (i == 18) {
				ans.push_back("s");
			}
			else if (i == 19) {
				ans.push_back("t");
			}
			else if (i == 20) {
				ans.push_back("u");
			}
			else if (i == 21) {
				ans.push_back("v");
			}
			else if (i == 22) {
				ans.push_back("w");
			}
			else if (i == 23) {
				ans.push_back("x");
			}
			else if (i == 24) {
				ans.push_back("y");
			}
			else {
				ans.push_back("z");
			}

		}
	}

	sort(ans.begin(),ans.end());

	string s = "";

	for (i = 0; i < ans.size(); i++) {
		s += ans[i];
	}
	cout << s << endl;

	return 0;
}