#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string t;
	int n;
	vector<int> c;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i){
		cin >> s[i];
		c.push_back(0);
	}
	for (int i = 0; i <= 26; ++i){
		for (int j = 0; j < n; ++j){
			c[j] = 0;
		}
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < s[j].size(); ++k){
				if (s[j][k] == 'a'+i){
					c[j]++;
				}
			}
		}
		sort(c.begin(), c.end());
		for (int j = 0; j < c[0]; ++j){
			printf("%c", char('a'+i));
		}
	}
	printf("\n");
	return 0;
}