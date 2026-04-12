#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>

#define INF 1000000000000000000
using namespace std;
typedef long long ll;
#define sheep true
#define wolf false

int main(){
	bool park[100010];
	bool inf[100010];
	string str;
	int n;
	cin >> n;
	cin >> str;
	bool exist = false;
	for (int j = 0; j < 4; j++) {
		park[0] = (j/2==0);
		park[1] = (j%2==0);
		for (int i = 2; i < n; i++) {
			bool temp;
			temp = (str[i - 1] == 'o' ? !(true xor park[i - 1]) : !(false xor park[i - 1]));
			park[i] = (temp ? park[i - 2] : !park[i - 2]);
		}
		bool temp1,tempn;
		temp1 = (str[n - 1] == 'o' ? !(true xor park[n - 1]) : !(false xor park[n - 1]));
		temp1 = (temp1 ? park[n-2] : !park[n - 2]);
		tempn = (str[0] == 'o' ? !(true xor park[0]) : !(false xor park[0]));
		tempn = (tempn ? park[1] : !park[1]);
		if (temp1 == park[0] && tempn == park[n - 1]) {
			exist = true;
			break;
		}
	}
	if (exist) {
		for (int i = 0; i < n; i++) {
			cout << (park[i] ? 'S' : 'W');
		}
		cout << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}
