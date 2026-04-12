#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	vector<vector<int>> a(n, vector < int>(26));
	vector<int> mini(26,INF) ;
	for (int i = 0; i < n; i++) {
		cin >> s.at(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s.at(i).size(); j++) {
			a.at(i).at(s.at(i)[j] - 'a')++;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < n; j++) {
			if (a.at(j).at(i) < mini.at(i))mini.at(i) = a.at(j).at(i);
		}
	}

	for (int i = 0; i < mini.at(0); i++) {
		cout << 'a';
	}
	for (int i = 0; i < mini.at(1); i++) {
		cout << 'b';
	}
	for (int i = 0; i < mini.at(2); i++) {
		cout << 'c';
	}
	for (int i = 0; i < mini.at(3); i++) {
		cout << 'd';
	}
	for (int i = 0; i < mini.at(4); i++) {
		cout << 'e';
	}
	for (int i = 0; i < mini.at(5); i++) {
		cout << 'f';
	}
	for (int i = 0; i < mini.at(6); i++) {
		cout << 'g';
	}
	for (int i = 0; i < mini.at(7); i++) {
		cout << 'h';
	}
		for (int i = 0; i < mini.at(8); i++) {
			cout << 'i';
		}
		for (int i = 0; i < mini.at(9); i++) {
			cout << 'j';
		}
		for (int i = 0; i < mini.at(10); i++) {
			cout << 'k';
		}
		for (int i = 0; i < mini.at(11); i++) {
			cout << 'l';
		}
		for (int i = 0; i < mini.at(12); i++) {
			cout << 'm';
		}
		for (int i = 0; i < mini.at(13); i++) {
			cout << 'n';
		}
		for (int i = 0; i < mini.at(14); i++) {
			cout << 'o';
		}
		for (int i = 0; i < mini.at(15); i++) {
			cout << 'p';
		}
		for (int i = 0; i < mini.at(16); i++) {
			cout << 'q';
		}
		for (int i = 0; i < mini.at(17); i++) {
			cout << 'r';
		}
		for (int i = 0; i < mini.at(18); i++) {
			cout << 's';
		}
		for (int i = 0; i < mini.at(19); i++) {
			cout << 't';
		}
		for (int i = 0; i < mini.at(20); i++) {
				cout << 'u';
			}
		for (int i = 0; i < mini.at(21); i++) {
				cout << 'v';
			}
		for (int i = 0; i < mini.at(22); i++) {
				cout << 'w';
			}
		for (int i = 0; i < mini.at(23); i++) {
					cout << 'x';
				}
		for (int i = 0; i < mini.at(24); i++) {
					cout << 'y';
				}
		for (int i = 0; i < mini.at(25); i++) {
			cout << 'z';
				}
		cout << endl;
		
	





		return 0;
}