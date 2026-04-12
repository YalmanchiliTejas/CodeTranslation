#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int total = n*800;
	int sub = (n/15)*200;
	cout << total-sub << endl;
	return 0;
}