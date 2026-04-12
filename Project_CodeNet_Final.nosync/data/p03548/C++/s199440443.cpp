
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<math.h>
#include<unordered_set>
using namespace std;

int main() {
	int X, Y, Z;
	int cnt = 0;
	cin >> X >> Y >> Z;
	
	X -= Z;
	while (X >= Y + Z) {
		X = X - Y - Z;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}