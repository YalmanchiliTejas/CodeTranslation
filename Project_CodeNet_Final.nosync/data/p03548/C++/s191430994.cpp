#include<iostream>
using namespace std;

int main(){
	int X, Y, Z;
	cin >> X >> Y >> Z;
	
	int count = (X-Z)/(Y+Z);
	
	cout << count << endl;
	return 0;
}
