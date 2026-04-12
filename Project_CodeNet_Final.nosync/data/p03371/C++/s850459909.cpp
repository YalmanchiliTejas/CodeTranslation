#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int res = a * x + b * y;
	int Max = max(x, y);
	for (int i = 1; i <= Max; i++) {
		int tmp = 0;
		tmp+=2 * c * i ;
		if (x - i>0) {
			tmp += (x - i) * a;
		}
		if (y - i>0){
			tmp += (y - i) * b;
		}
		if (res > tmp)res = tmp;
	}
	cout << res << endl;
}