
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
	int h, w;
	cin >> h >> w;
	vector<string> a(h+2);
	a[0] = string(w + 2, ',');
	for (int i = 1;i <=h;i++) {
		string s;
		cin >> s;
		a[i] = ".";
		a[i] += s;
		a[i] += '.';
	}
	a[h + 1] = string(w + 2, ',');

	bool canConsist = true;
	for (int i = 1; i <=h;i++) {
		for (int j = 1; j <=w;j++) {
			
			if (a[i][j] == '#') {
				
				int cnt = 0;
				if (a[i][j + 1] == '#') {
					cnt++;
				}

				if (a[i][j - 1] == '#') {
					cnt++;
				}
				if (a[i + 1][j] == '#') {
					cnt++;
				}
				if (a[i - 1][j] == '#') {
					cnt++;
				}

				if (cnt > 2) {
					canConsist = false;
					break;
				}
				if (i == 1 && j == 1 && cnt >= 2) {
					canConsist = false;

					break;
				}
				

				if (i == h && j == w) {
					if (cnt >= 2) {
						canConsist = false;
					}
					break;
				}

				if (a[i + 1][j] != '#' && a[i][j + 1] != '#') {
					canConsist = false;
					break;
				}
				
				
			}
			
		}

		if (!canConsist) {
			break;
		}
		
	}


	cout << (canConsist ? "Possible" : "Impossible") << endl;
}

