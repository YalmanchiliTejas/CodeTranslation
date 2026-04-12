#include <iostream>

using namespace std;

int main(){
	uint32_t x = 0;

	cin >> x;

	if(x == 3 || x == 5 || x == 7){
		cout << u8"YES" << endl;
	}
	else{
		cout << u8"NO" << endl;
	}

	return(0);
}