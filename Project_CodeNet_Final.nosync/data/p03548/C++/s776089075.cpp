//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int sum = z, cnt = 0;
	while (true) {
		sum += z;
		sum += y;
		cnt++;
		if (sum >= x) {
			break;
		}
	}
	if (sum > x) cnt--;
	cout << cnt << endl;
}
