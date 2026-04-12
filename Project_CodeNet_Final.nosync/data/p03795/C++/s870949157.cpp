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

int main(){
	int n;
	cin >> n;
	int x, y;
	x = 800 * n;
	y = 200 * (n/ 15);
	cout << x - y << endl;
	return 0;
}
