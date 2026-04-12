#include <iostream>
using namespace std;
#include <algorithm>

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	
	//下二桁が4で割り切れたたら4の倍数
	
	int u2d = g*10 + b;
	
	if(u2d%4 == 0 ) cout << "YES";
	else cout << "NO";
	
	cout << endl;
	
	return 0;
}