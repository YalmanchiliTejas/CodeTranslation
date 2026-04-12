
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

string s;
int k;



int main() {

	cin >> s >> k;
	int len = s.length();
	ll ans = 0;
	if (len - 1 >= k) {
		ans = 1;
		for (int i = 0;i < k;i++) {
			ans *= (len - 1 - i)*9;
		}
		for (int i = k; i > 0;i--) {
			ans /= i;
		}
	}
	else {
		ans = 0;
	}
	
	
	
	int cnt = 0;
	
	for (int i = 0; i <len ;i++) {
		int num = s[i] - '0';
		if (num > 0) {
			int tmp;
			if (cnt > 0) {
				tmp = 1;

				for (int l = 0;l < k - cnt;l++) {
					tmp *= (len - 1 - i - l) * 9;
				}
				for (int l = k - cnt; l > 0;l--) {
					tmp /= l;
				}

				ans += tmp;

			}
			cnt++;
			if (cnt == k) {
				ans += num;
				break;
			}
			tmp = num-1;

			for (int l = 0;l < k - cnt;l++) {
				tmp *= (len - 1 - i - l) * 9;
			}
			for (int l = k - cnt; l > 0;l--) {
				tmp /= l;
			}

			ans += tmp;



		}
		
	}


	cout << ans << endl;
}



