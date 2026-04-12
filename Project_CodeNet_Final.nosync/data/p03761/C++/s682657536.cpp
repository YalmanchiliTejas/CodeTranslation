#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<30)

int n, c[50][26];
signed main(){

	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++){
			c[i][s[j] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++){

		int r = INF;
		for (int j = 0; j < n; j++){
			if (c[j][i] < r) r = c[j][i];
		}

		for (int k = 0; k < r; k++){
			cout << (char)('a' + i);
		}
	}
	cout << endl;

	return 0;
}
