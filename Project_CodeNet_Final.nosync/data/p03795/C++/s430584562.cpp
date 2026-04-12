#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x = n * 800;
	int y = n / 15 * 200;

	cout << x - y << endl;

	return 0;
}