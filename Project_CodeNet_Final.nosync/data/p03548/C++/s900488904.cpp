#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int x, y, z;
	cin >> x >> y >> z;
	int w = x - (2*z);
	int now = 0; 
	int cnt = 0;
	for(;;){
		now += y;
		if(now > w){
			break;
		}else{
			now += z;
			cnt++;
		}
	}

	cout << cnt << endl;
}