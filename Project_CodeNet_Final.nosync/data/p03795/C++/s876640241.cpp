#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int one_lunch = 800;
	int discount = 200;
	int time = 15;
	long x = n * one_lunch;
	long y = ((int)(n/time))*discount;

	cout << x - y << endl;
	return 0;
}
