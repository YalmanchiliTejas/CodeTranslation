#include <iostream>
using namespace std;
int main(void){
	int x, y, z;
	int cnt = 0;
	cin >> x >> y >> z;
	while(x >= y+z*2){
		x -= y + z;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}