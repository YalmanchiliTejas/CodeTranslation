#include<iostream>
#include<string>
#include<vector>
#include<stdbool.h>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<set>
#include<string>
#include<stdlib.h>
typedef long long ll;
using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	for (int i = 0;i <= X;i++) {
		if (X < (Y + Z)*i + Z) {
			cout << i-1 << endl;
			return 0;
		}
		else if (X == (Y + Z)*i + Z) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}