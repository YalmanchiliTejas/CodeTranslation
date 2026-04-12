
#include <iostream>
using namespace std;


int main(){
	int x,y,z;
	cin >> x >> y >> z;
	
	int answer=0;
	x -= z;
	answer = x/(y+z);
	x %= (y+z);
//	if(x >= y){
//		answer ++;
//	}
	
	cout << answer << endl;
//	x-=y;
//	if(x > 0){
//		cout << x/(y+z)+1 << endl;
//	}else{
//		cout << "0" << endl;
//	}
//	cout << x/(y+z) + 1 << endl;
	return 0;
}
