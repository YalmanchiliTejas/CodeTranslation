#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, z;

	cin >> x >> y >> z;

	x -= z;

	int cnt = 0;

	while(1){
		if(x>=(y+z)){
			cnt++;
			x -= (y + z);
		}else{
			break;
		}
	}

	cout << cnt << endl;
}