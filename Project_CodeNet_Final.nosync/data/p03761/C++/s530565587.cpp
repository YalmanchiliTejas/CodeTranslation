#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9

int num[26];

void input(bool isFirst) {
	string S;
	cin >> S;
	int tmp[26];
	for (int i = 0; i < 26; i++) tmp[i] = 0;
	for (int i = 0; i < S.size(); i++) {
		tmp[S[i] - 'a']++;
	}
	if (isFirst) {
		for (int i = 0; i < 26; i++) num[i] = tmp[i];
	}
	else {
		for (int i = 0; i < 26; i++) num[i] = min(num[i], tmp[i]);
	}
}

int main() {
	int n; cin >> n;
	input(true);
	for (int i = 0; i < n - 1; i++) input(false);

	for (int i = 0; i < 26; i++) {
		char c = char(i + 'a');
		for (int j = 0; j < num[i]; j++) cout << c;
	}
	cout << endl;

	return 0;
}