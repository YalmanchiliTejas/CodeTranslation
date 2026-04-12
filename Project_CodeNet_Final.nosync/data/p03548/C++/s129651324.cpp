#include<iostream>
using namespace std;
int main(){
	int n,z,x;
	cin >> n >> z >> x;
	n-=x;
	n=n/(z+x);
	cout << n << endl;
	return 0;
} 