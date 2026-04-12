#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main() {
	int n, k; string s;
	cin >> n >> s >> k;
	char c = s[k - 1];
	for (int i = 0; i < n; i++) {
		if (s[i] != c) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}