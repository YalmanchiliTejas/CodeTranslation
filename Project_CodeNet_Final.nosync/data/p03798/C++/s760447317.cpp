
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n;
	string s;
	cin >> n >> s;
	
	string ans;
	for (int b = 0; b < 4;b++) {
		vector<bool> isSheep(n, false);

		isSheep[0] = (b & 1);
		isSheep[1] = ((b >> 1) & 1);

		for (int i = 2; i < n;i++) {
			if (isSheep[i - 1] ^ s[i - 1] == 'o') {
				isSheep[i] = !isSheep[i - 2];
			}
			else {
				isSheep[i] = isSheep[i - 2];
			}
		}

		if ((isSheep[n - 2] ^ isSheep[0]) == (isSheep[n - 1] ^ s[n - 1] == 'o') && (isSheep[n - 1] ^ isSheep[1]) == (isSheep[0] ^ s[0] == 'o')) {
			string tmp(n, ' ');
			for (int i = 0; i < n;i++) {
				tmp[i] = isSheep[i] ? 'S' : 'W';
			}
			ans = tmp;
		}
	}

	if (ans.length() == 0) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

}



