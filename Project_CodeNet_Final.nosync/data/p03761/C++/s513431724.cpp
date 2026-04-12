#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> words(n);
	vector<string> uniwords(n);
	int minwords = 50;
	int minnumber;
	for (int i = 0;i < n;i++) {
		cin >> words[i];
		uniwords[i] = words[i];
		sort(uniwords[i].begin(), uniwords[i].end());
		uniwords[i].erase(unique(uniwords[i].begin(), uniwords[i].end()), uniwords[i].end());
		if (minwords > uniwords[i].size()) {
			minwords = uniwords[i].size();
			minnumber = i;
		}
	}
	vector<char>s;
	int counter1 = 0;
	int counter2 = 50;
	for (int k = 0;k < minwords;k++) {
		counter2 = 50;
		for (int i = 0;i < n;i++) {
			counter1 = 0;
			for (int j = 0;j < words[i].size();j++) {
				if (uniwords[minnumber][k] == words[i][j]) {
					counter1++;
				}
			}
			counter2 = min(counter1, counter2);
		}
		for (int i = 0;i < counter2;i++) {
			s.push_back(uniwords[minnumber][k]);
		}
	}
	for (int i = 0;i < s.size();i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}