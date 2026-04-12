#include <iostream>
using namespace std;
int main(){
	int x,a,b;
	cin >> x >> a >> b;

	x = 100*x + 10*a +b;
	if (x%4==0) {
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}