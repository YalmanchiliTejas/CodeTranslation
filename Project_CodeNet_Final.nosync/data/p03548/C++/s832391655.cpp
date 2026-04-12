#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main() {
	int x, y, z; cin >> x >> y >> z;
	int ans = 0;
	for(int i=1;i<=(x-z)/(y+z);i++){
		ans = i;
	}
	cout << ans << endl;
	return 0;
}