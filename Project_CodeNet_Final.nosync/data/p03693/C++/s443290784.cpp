#include<iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	a = a * 100 + b * 10 + c;
	if (!(a % 4)) cout << "YES" << endl;
	else cout << "NO" << endl;
}