#include <vector> // vectorを使うためにインクルードする
#include <iostream>
using namespace std;


int main() {
	int x,y,z;
	cin >> x >> y >> z;
	if((y*10+z) %4 == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	}
