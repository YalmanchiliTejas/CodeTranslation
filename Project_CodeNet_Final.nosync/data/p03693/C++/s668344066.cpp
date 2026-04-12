#include<iostream>
using namespace std;

int main(){
	int r, g, m;
	cin >> r >> g >> m;
	int ans = (10*g + m) % 4;
	if(ans == 0)	cout << "YES" << endl;
	else		cout << "NO" << endl;
	return 0;
}
