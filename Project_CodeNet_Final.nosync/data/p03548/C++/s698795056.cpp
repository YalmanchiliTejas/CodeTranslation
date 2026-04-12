#include <bits/stdc++.h>
using namespace std;

int main(){
	int X, Y, Z;
	cin >> X >> Y >> Z;
	X -= Z;
	int a = X / (Y+Z);
	cout << a << endl;
}