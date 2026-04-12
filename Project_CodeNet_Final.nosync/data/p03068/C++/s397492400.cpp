#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;


int main(void) {
	int n, k;
	string s;
	cin >> n >> s >> k;
	char sk = s[k - 1];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != sk) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}