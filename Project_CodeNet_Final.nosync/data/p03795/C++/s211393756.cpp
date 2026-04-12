#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a = n / 15;
	
	int x = n * 800;
	int y = a * 200;

	cout << x - y << endl;
}