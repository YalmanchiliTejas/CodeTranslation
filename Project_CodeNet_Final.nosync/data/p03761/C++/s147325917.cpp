#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include <typeinfo>
#include <stdlib.h>
#define ll long long
const int MOD = 1000000007;
using namespace std;

int main() {
	int n, a[50][(int)'z' + 1] = {};
	string s[50], al = "abcdefghijklmnopqrstuvwxyz";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++) {
			a[i][(int)s[i][j]]++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = (int)'a'; j <= (int)'z'; j++) {
			a[0][j] = min(a[0][j],min(a[i][j], a[i + 1][j]));
		}
	}
	for (int i = (int)'a'; i <= (int)'z'; i++) {
		for (int j = 0; j < a[0][i]; j++) {
			cout << al[i - (int)'a'];
		}
	}
	cout << endl;
	return 0;
}