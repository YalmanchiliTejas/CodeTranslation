#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i <= s.size() - 2; i++) {
		if (s[i] == 'A'&&s[i+1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}