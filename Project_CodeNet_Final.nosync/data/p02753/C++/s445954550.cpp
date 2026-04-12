#include <bits/stdc++.h>
using namespace std;

int main() {
	


	string s;
	cin >> s;
	int freq[2] = {0};
	for (int i = 0; i < s.length(); ++i) {
		if(s[i] == 'A') {
			freq[0]++;
		} else {
			freq[1]++;
		}
	}
	if(freq[0]&&freq[1]) 
		cout<<"Yes";
	else
		cout<<"No";
	return 0;

}