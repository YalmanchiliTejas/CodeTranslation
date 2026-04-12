#include <iostream>

using namespace std;

int main(){
	int x, y, z;
	cin >> x >> y >> z;
	int i;
	for(i = 0; i < 1000000; i++){
		int a, b;
		a = i * y;
		b = (i + 1) * z;
		if(a + b > x){
			cout << i - 1 << endl;
			return 0;
		}
	}
}