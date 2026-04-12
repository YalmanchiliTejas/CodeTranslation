#include<iostream>
using namespace std;
int main(){
	int n; cin >> n;
	long a = n * 800;
	long b = (n - (n % 15)) / 15 * 200;
	cout << a - b << endl;
	char c; cin >> c;
}