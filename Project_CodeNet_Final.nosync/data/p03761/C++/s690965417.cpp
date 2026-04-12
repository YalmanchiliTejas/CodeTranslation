#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool find(vector<char>l, char c) {
	for (int i = 0; i < l.size(); i++)
		if (l[i] == c)return true;
	return false;
}
int main() {
	int n; cin >> n;
	string s[60];
	vector<char>l;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			if (!find(l, s[i][j]))l.push_back(s[i][j]);
	}
	sort(l.begin(), l.end());
	string str;
	for (int i = 0; i < l.size(); i++){
		int kn = 60;
		for (int j = 0; j < n; j++){
			int sum = 0;
			for (int k = 0; k < s[j].size(); k++){
				if (s[j][k] == l[i])sum++;
			}
			kn = min(sum, kn);
		}
		for (int j = 0; j < kn; j++)str += l[i];
	}
	cout << str << endl;
}