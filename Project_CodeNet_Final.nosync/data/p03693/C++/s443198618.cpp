#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	int r, g, b;
	int ans;
	string out = "NO";
	cin >> r >> g >> b;
	ans = g*10+b;
	if(ans%4 == 0){
		out = "YES";
	}
	cout << out << endl;
	
	return 0;
}