#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s[100];
	for (int i = 0;i < n;i++)cin >> s[i];
	int cha[30] = {};
	for (int j = 0;j < s[0].size();j++) {
		cha[s[0][j] - 'a']++;
	}
	for (int i = 1;i < n;i++) {
		int now[30] = {};
		for (int j = 0;j < s[i].size();j++) {
			now[s[i][j] - 'a']++;
		}
		for (int j = 0;j <= 'z' - 'a';j++) {
			if (cha[j] > now[j])cha[j] = now[j];
		}
	}
	string p = "abcdefghijklmnopqrstuvwxyz";
	for (int i=0;i <p.size();i++) {
		for (int j = 0;j < cha[i];j++)cout << p[i];
	}
	cout << endl;
}