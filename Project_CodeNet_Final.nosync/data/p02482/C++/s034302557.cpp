#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int a , b;
	cin >> a >> b;
	a<b ? cout << "a < b" : a>b ? cout << "a > b" : cout << "a == b";
	cout << endl;
	return 0; 
}