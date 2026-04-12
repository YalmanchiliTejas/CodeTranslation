#include<iostream>
#include<string>
using namespace std;
int main(){
	
	int x, y, z, a = 0;
	cin >> x >> y >> z;
	a = x;
	for (int i = 0; i < x; i++){
		a -= z;
		a -= y;
		if (a < z){
			cout << i << endl;
			break;
		}
	}


	return 0;
}