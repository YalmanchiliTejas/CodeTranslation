#include<iostream>
#include<string>
//#include<array>
#include<algorithm>
//#include<deque>
#include<vector>
//#include<utility>
//#include<set>
//#include<map>
//#include<list>

int main(void) {
	using namespace std;
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	int res = x / (y + z);
	cout << res << endl;
}