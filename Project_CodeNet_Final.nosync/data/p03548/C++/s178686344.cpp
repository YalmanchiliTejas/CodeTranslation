#include<iostream>
using namespace std;
int main(){

	int x, y, z,l=0;
	cin >> x >> y >> z;
	l = x;

	for (int i = 0; i < x; i++){
		l -= y;
		l -= z;

		if (l < z){
			cout << i << endl;
			break;
		}
	}

	return 0;
}